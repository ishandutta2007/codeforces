#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=1000000007;
ll n,m;
ll fac[10000005],inv[10000005];

ll mod(ll x){return x>=cys?x-cys:x;}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

ll solve(ll x){
	if(m<x) return fac[n]*fac[n-x+m]%cys*inv[n-x]%cys*inv[n-x]%cys;
	else return qpow(n,m-x)*fac[n]%cys*inv[n-x]%cys*fac[n]%cys*inv[n-x]%cys;
}

int main(){
	n=readint(); m=readint();
	fac[0]=inv[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%cys;
	inv[n]=qpow(fac[n],cys-2);
	for(int i=n-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%cys;
	ll ans=0;
	for(int i=1;i<=n;i++) ans=mod(ans+solve(i));
	m--;
	for(int i=2;i<=n;i++) ans=mod(ans+cys-solve(i));
	printf("%lld\n",ans);
	return 0;
}