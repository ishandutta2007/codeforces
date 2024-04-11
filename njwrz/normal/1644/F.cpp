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
int ans[200005],f[200005],finv[200005],mod=998244353;

const int p = 998244353;
typedef complex<double> E;
 
const double pi = acos(-1);
 
int qpow(int a, int b, int p){
    int res = 1;
    for(; b; b >>= 1, a = a * a % p){
        if(b & 1) res = res * a % p;
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
    inv3 = qpow(3, p - 2, p);
    for(int i = 1; i <= N; i <<= 1) pow3[i] = qpow(3, (p - 1) / i, p);
    for(int i = 1; i <= N; i <<= 1) powinv3[i] = qpow(inv3, (p - 1) / i, p);
}
 
void NTT(int n, int* r, int f){
    bit_reverse(n, r);
    for(int i = 2; i <= n; i <<= 1){
        int m = i >> 1;
        for(int j = 0; j < n; j += i){
            int w = 1, wn = pow3[i];
            if(f == -1) wn = powinv3[i];
            for(int k = 0; k < m; k ++){
                int z = r[j + m + k] * w % p;
                r[j + m + k] = (r[j + k] - z + p) % p;
                r[j + k] = (r[j + k] + z) % p;
                w = w * wn % p;
            }
        }
    }
    if(f == -1){
        int inv = qpow(n, p - 2, p);
        for(int i = 0; i < n; i ++) r[i] = r[i] * inv % p;
    }
}
int ta[(1<<19)+5],tb[(1<<19)+5];
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
int t[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	if(k<=1||n==1){
		cout<<1;RE 0;
	}
	gmin(k,n);
	f[0]=1;
	FOR(i,1,n)f[i]=f[i-1]*i%mod;
	finv[n]=POW(f[n],mod-2);
	for(int i=n;i>=1;i--)finv[i-1]=finv[i]*i%mod;
	N=1<<19;
	pre();
	FOR(i,1,n){
		int m=(n+i-1)/i;
		int tk=min(k,m);
		N=1;
		while(N<=2*m+5)N*=2;
		rep(i,0,N)ta[i]=tb[i]=0;
		FOR(j,0,m){
			ta[j]=finv[j]*POW(j,m)%mod;
			if(j&1)tb[j]=mod-finv[j];else tb[j]=finv[j];
		}
		NTT(N,ta,1);
		NTT(N,tb,1);
		rep(i,0,N)ta[i]=ta[i]*tb[i]%mod;
		NTT(N,ta,-1);
		FOR(j,1,tk)add(ans[i],ta[j]);
		add(ans[i],mod-1);
	}
	for(int i=n;i>=1;i--){
		for(int j=i+i;j<=n;j+=i){
			add(ans[i],mod-ans[j]);
		}
	}
	cout<<ans[1];
	RE 0;
}