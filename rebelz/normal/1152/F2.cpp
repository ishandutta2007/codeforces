#include<bits/stdc++.h>

#define y1 dmytxdy
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=1000000007;
int n,k,m,N;
ll d[1005][215];

ll mod(ll x){return x>=cys?x-cys:x;}
void add(ll &x,ll y){x=mod(x+y);}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

namespace linear{
	ll res[10005],c[10005],md[10005];
	vi pl;
	void mul(ll *a,ll *b,int k){
		for(int i=0;i<k+k;i++) c[i]=0;
		for(int i=0;i<k;i++) for(int j=0;j<k;j++) c[i+j]=(c[i+j]+a[i]*b[j]%cys)%cys;
		for(int i=k+k-1;i>=k;i--) if(c[i]) for(auto x:pl) c[i-k+x]=(c[i-k+x]-c[i]*md[x]%cys)%cys;
		for(int i=0;i<k;i++) a[i]=c[i];
	}
	ll solve(ll n,vi a,vi b){
		ll ans=0,pnt=0,m=a.size();
		for(int i=0;i<m;i++) md[m-i-1]=-a[i];
		md[m]=1;
		pl.clear();
		for(int i=0;i<m;i++) res[i]=0;
		res[0]=1;
		for(int i=0;i<m;i++) if(md[i]!=0) pl.push_back(i);
		while((1ll<<pnt)<=n) pnt++;
		for(int p=pnt;p>=0;p--){
			mul(res,res,m);
			if((n>>p)&1){
				for(int i=m-1;i>=0;i--) res[i+1]=res[i];
				res[0]=0;
				for(auto x:pl) res[x]=(res[x]-res[m]*md[x]%cys)%cys;
			}
		}
		for(int i=0;i<m;i++) ans=(ans+res[i]*b[i]%cys)%cys;
		return ans<0?ans+cys:ans;
	}
	vi BM(vi x){
		vi r(0),g(0);
		ll c,d,p;
		for(int i=0;i<x.size();i++){
			d=-x[i];
			for(int j=0;j<r.size();j++) d=(d+r[j]*x[i-j-1])%cys;
			if(!d) continue;
			if(!r.size()){
				r.resize(i+1),p=i,c=d;
				continue;
			}
			ll k=-d*qpow(c,cys-2)%cys;
			vi tmp(i-p-1); tmp.push_back(-k);
			for(int i=0;i<g.size();i++) tmp.push_back(g[i]*k%cys);
			if(tmp.size()<r.size()) tmp.resize(r.size());
			for(int i=0;i<r.size();i++) tmp[i]=(tmp[i]+r[i])%cys;
			g=r,p=i,c=d;
			r=tmp;
		}
		for(int i=0;i<r.size();i++) r[i]=r[i]<0?r[i]+cys:r[i];
		return r;
	}
	ll work(vi a,ll n){
		vi eq=BM(a);
		return solve(n,eq,vi(a.begin(),a.begin()+eq.size()));
	}
}

int main(){
	n=readint(); k=readint(); m=readint();
	N=(k+1)*(1<<m);
	d[0][0]=1;
	vector<ll> v(0);
	for(int j=1;j<=200;j++){
		for(int i=0;i<N;i++){
			int t=i/(1<<m),mask=i%(1<<m);
			add(d[j][t*(1<<m)+((mask<<1)&((1<<m)-1))],d[j-1][i]);
			int cnt=0;
			for(int j=0;j<m;j++) cnt+=(i>>j)&1;
			if(t<k) add(d[j][(t+1)*(1<<m)+((mask<<1)&((1<<m)-1)|1)],(1+cnt)*d[j-1][i]%cys);
		}
		ll ans=0;
		for(int i=k*(1<<m);i<N;i++) ans=(ans+d[j][i])%cys;
		v.pb(ans);
	}
	printf("%lld\n",linear::work(v,n-1));
	return 0;
}