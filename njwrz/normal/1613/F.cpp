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
using namespace std;
const int mod=998244353;
typedef complex<double> E;
const double pi=acos(-1);
int qpow(int a,int b,int mod){
    int res=1;
    for(;b;b>>=1,a=a*a%mod){
        if(b&1)res=res*a%mod;
    }
    RE res;
}
int N; 
void bit_reverse(int n,int* r){
    for(int i=0,j=0;i<n;i++){
        if(i>j)swap(r[i],r[j]);
        for(int l=n>>1;(j^=l)<l;l>>=1);
    }
}
int inv3;
int pow3[(1<<21)+5],powinv3[(1<<21)+5];
void pre(int n){
    inv3=qpow(3,mod-2,mod);
    for(int i=1;i<=n;i<<=1)pow3[i]=qpow(3,(mod-1)/i,mod);
    for(int i=1;i<=n;i<<=1)powinv3[i]=qpow(inv3,(mod-1)/i,mod);
}
void NTT(int n,int* r,int f){
    bit_reverse(n,r);
    for(int i=2;i<=n;i<<=1){
        int m=i>>1;
        for(int j=0;j<n;j+=i){
            int w=1,wn=pow3[i];
            if(f==-1)wn=powinv3[i];
            for(int k=0;k<m;k++){
                int z=r[j+m+k]*w%mod;
                r[j+m+k]=(r[j+k]-z+mod)%mod;
                r[j+k]=(r[j+k]+z)%mod;
                w=w*wn%mod;
            }
        }
    }
    if(f==-1){
        int inv=qpow(n,mod-2,mod);
        for(int i=0;i<n;i++)r[i]=r[i]*inv%mod;
    }
}
int ta[(1<<18)+5],tb[(1<<19)+5];
int n;
V<int> v[250005];
int cnt[250005],len;
void dfs(int x,int y){
	int sum=0;
	for(auto u:v[x])if(u!=y){
		sum++;
		dfs(u,x);
	}
	if(sum)cnt[++len]=sum;
}
V<int> get(int l,int r){
	if(l==r){
		V<int> p(2,0);
		p[0]=1;p[1]=cnt[l];
		RE p;
	}
	int mid=(l+r)>>1;
	V<int> tl=get(l,mid),tr=get(mid+1,r);
	int siz=tl.size()+tr.size()-1;
	V<int> p(siz,0);
	N=1;
	while(N<siz)N*=2;
	rep(i,0,tl.size())ta[i]=tl[i];
	rep(i,tl.size(),N)ta[i]=0;
	rep(i,0,tr.size())tb[i]=tr[i];
	rep(i,tr.size(),N)tb[i]=0;
	NTT(N,ta,1);
	NTT(N,tb,1);
	rep(i,0,N)ta[i]=ta[i]*tb[i]%mod;
	NTT(N,ta,-1);
	rep(i,0,siz)p[i]=ta[i];
	RE p;
}
int f[250005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	pre(1<<19);
	FOR(i,2,n){
		int x,y;
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	dfs(1,-1);
	f[0]=1;
	FOR(i,1,n)f[i]=f[i-1]*i%mod;
	V<int> tv=get(1,len);
	int ans=0;
	rep(i,0,tv.size()){
		if(i&1){
			ans=(ans-f[n-i]*tv[i]%mod+mod)%mod;
		}else ans=(ans+f[n-i]*tv[i])%mod;
	}
	cout<<ans;
	RE 0;
}