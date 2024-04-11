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

int n,m;
ll a[200005],b[200005];
vector<pll> vec;

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=m;i++) b[i]=readint();
	sort(b+1,b+m+1);
	for(int i=1;i<=n;i++){
		int pl=lower_bound(b+1,b+m+1,(i-1)*100)-b;
		ll d=1ll<<60;
		if(pl<=m) chkmin(d,b[pl]-(i-1)*100);
		if(pl>1) chkmin(d,(i-1)*100-b[pl-1]);
		if(d) vec.pb(mp(2*((i-1)*100-d)+1,a[i])),vec.pb(mp(2*((i-1)*100+d),-a[i]));
	}
	sort(vec.begin(),vec.end());
	ll ans=0,now=0;
	for(auto r:vec){
		now+=r.se;
		chkmax(ans,now);
	}
	printf("%lld\n",ans);
	return 0;
}