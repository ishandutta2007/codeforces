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

ll n,d,m;
ll a[100005],s[100005];

int main(){
	n=readint(); d=readint(); m=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	sort(a+1,a+n+1);
	int pl=0;
	for(int i=1;i<=n;i++) if(a[i]<=m) pl=i;
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	ll ans=0;
	for(int i=0;i<=n;i++){
		ll tmp;
		if(!i) tmp=0;
		else tmp=1ll*(i-1)*(d+1)+1;
		if(tmp>n||i>n-pl) continue;
		chkmax(ans,s[pl]-s[max(0ll,pl-(n-tmp))]+s[n]-s[n-i]);
	}
	printf("%lld\n",ans);
	return 0;
}