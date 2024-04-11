#include<bits/stdc++.h>

#define y1 dmytxdy
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
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

const int cys=998244353;
int n,m;
int a[1005];

ll mod(ll x){return x>=cys?x-cys:x;}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

int main(){
	m=readint();
	for(int i=1;i<=m;i++) a[i]=readint();
	sort(a+1,a+m+1);
	for(int i=1;i<=m;i++) n+=a[i];
	int pl=1;
	ll s=cys-2,b=1,g=cys-2,ans=0;
	while(pl<=m&&a[pl]==1) ans=(ans+s*qpow(b,cys-2))%cys,pl++;
	for(int i=2;i<=n;i++){
		g=g*(n+n-i+1)%cys;
		b=b*(n-i+1)%cys;
		s=s*(n-i+1)%cys;
		s=mod(s+g);
		while(pl<=m&&a[pl]==i) ans=(ans+s*qpow(b,cys-2))%cys,pl++;
	}
	ans=mod(ans+cys-s*qpow(b,cys-2)%cys);
	printf("%lld\n",ans);
	return 0;
}