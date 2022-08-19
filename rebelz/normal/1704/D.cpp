// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=998244353;
int n,m;
ll fac[1000005],inv[1000005],a[1000005];

ll mod(ll x){return x>=cys?x-cys:x;}
ll C(ll x,ll y){return x<y?0:fac[x]*inv[y]%cys*inv[x-y]%cys;}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

int main(){
	int T=readint();
	while(T--){
		n=readint(); m=readint();
		ll mina=1ll<<60;
		for(int i=1;i<=n;i++){
			a[i]=0;
			for(int j=1;j<=m;j++) a[i]+=readint()*j;
			chkmin(mina,a[i]);
		}
		ll ans1=0,ans2=0;
		for(int i=1;i<=n;i++) if(a[i]!=mina) ans1=i,ans2=a[i]-mina;
		printf("%lld %lld\n",ans1,ans2);
	}
	return 0;
}