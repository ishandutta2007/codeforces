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

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int N=400002,cys=1000000007;
int n;
ll fac[400005],inv[400005],a[200005];

ll C(ll x,ll y){return x<y?0:fac[x]*inv[y]%cys*inv[x-y]%cys;}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

int main(){
	fac[0]=inv[0]=1;
	for(int i=1;i<=N;i++) fac[i]=fac[i-1]*i%cys;
	inv[N]=qpow(fac[N],cys-2);
	for(int i=N-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%cys;
	n=readint()+1;
	for(int i=0;i<n;i++) a[i]=readint();
	ll ans=0;
	for(int i=0;i<n;i++) ans=(ans+C(i+a[i],i+1))%cys;
	printf("%lld\n",ans);
	return 0;
}