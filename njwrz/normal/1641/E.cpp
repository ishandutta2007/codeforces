#include<bits/stdc++.h>
#define int long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
int mod=998244353;
typedef complex<double> E;
const double pi = acos(-1);
int qpow(int a, int b, int mod){
    int res = 1;
    for(; b; b >>= 1, a = a * a % mod){
        if(b & 1) res = res * a % mod;
    }
    return res;
}
 
int N; 
 
void bit_reverse(int n, int* r){
    for(int i = 0, j = 0; i < n; i ++){
        if(i > j) swap(r[i], r[j]);
        for(int l = n >> 1; (j ^= l) < l; l >>= 1);
    }
}
int inv3;
int pow3[(1<<21)+5], powinv3[(1<<21)+5];
 
void pre(){
    inv3 = qpow(3, mod - 2, mod);
    for(int i = 1; i <= N; i <<= 1) pow3[i] = qpow(3, (mod - 1) / i, mod);
    for(int i = 1; i <= N; i <<= 1) powinv3[i] = qpow(inv3, (mod - 1) / i, mod);
}
 
void NTT(int n, int* r, int f){
    bit_reverse(n, r);
    for(int i = 2; i <= n; i <<= 1){
        int m = i >> 1;
        for(int j = 0; j < n; j += i){
            int w = 1, wn = pow3[i];
            if(f == -1) wn = powinv3[i];
            for(int k = 0; k < m; k ++){
                int z = r[j + m + k] * w % mod;
                r[j + m + k] = (r[j + k] - z + mod) % mod;
                r[j + k] = (r[j + k] + z) % mod;
                w = w * wn % mod;
            }
        }
    }
    if(f == -1){
        int inv = qpow(n, mod - 2, mod);
        for(int i = 0; i < n; i ++) r[i] = r[i] * inv % mod;
    }
}
int ta[(1<<18)+5],tb[(1<<18)+5];
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
int POW(int x,int y){
	int re=1;
	while(y){
		if(y&1)re=re*x%mod;
		x=x*x%mod;
		y/=2;
	}
	RE re;
}
int n,m,a[100005],b[100005],p2[100005];
P<int,int> p[100005];
int val[200005]; 
void solve(int l,int r){
	if(l==r)RE ;
	int mid=(l+r)>>1;
	int t=r-l+1;
	N=1;
	while(N<t)N*=2;
	rep(i,0,N)ta[i]=tb[i]=0;
	FOR(i,l,mid)ta[i-l]=p[i].F;
	FOR(i,mid+1,r)tb[i-mid]=p[i].S;
	NTT(N,ta,1);
	NTT(N,tb,1);
	rep(i,0,N)ta[i]=ta[i]*tb[i]%mod;
	NTT(N,ta,-1);
	FOR(i,0,r-l){
		add(val[i+mid+l],ta[i]);
	}
	solve(l,mid);solve(mid+1,r);
}
int sum[200005],ans;
int solve(int t=0){
	int ts=0;ans=0;
	FOR(i,0,n)p[i]=MP(0,0);
	FOR(i,1,n+n)val[i]=0;
	FOR(i,1,m)p[b[i]]=MP(p2[i-1],p2[m-i]*b[i]%mod);
	solve(1,n);
	FOR(i,1,n)add(val[1],p[i].S);
	FOR(i,1,n+n)sum[i]=(sum[i-1]+val[i])%mod;
	int it=0,mi=0;ts=1;
	FOR(i,1,n){
		add(ans,sum[i*2-t]*a[i]%mod);
		add(ans,mod-mi*a[i]%mod);
//		cout<<ans<<' ';
		add(mi,p[i].S*ts%mod);
		add(ts,p[i].F);
	}
//	cout<<'\n';
	FOR(i,1,m)p[b[i]]=MP(p2[i-1],p2[m-i]);
	FOR(i,1,n+n)val[i]=0;
	solve(1,n);
	FOR(i,1,n)add(val[1],p[i].S);
	FOR(i,1,n+n)sum[i]=(sum[i-1]+val[i])%mod;
	it=0,mi=0;ts=1;
	FOR(i,1,n){
		add(ans,mod-sum[i*2-t]*i%mod*a[i]%mod);
		add(ans,mi*a[i]%mod*i%mod);
//		cout<<ans<<' ';
		add(mi,p[i].S*ts%mod);
		add(ts,p[i].F);
	}
//	cout<<'\n';
	RE ans;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	N=(1<<18);pre();
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,m)cin>>b[i];
	p2[0]=1;
	FOR(i,1,n)p2[i]=p2[i-1]*2%mod;
	int sum=solve();
	reverse(a+1,a+n+1);
	reverse(b+1,b+m+1);
	FOR(i,1,m)b[i]=n-b[i]+1;
	add(sum,solve(1));
//	cout<<sum<<' ';
	cout<<sum*POW(p2[m]-1,mod-2)%mod;
	RE 0;
}