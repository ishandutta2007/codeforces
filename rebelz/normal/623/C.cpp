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

int n;
ll minpre[100005],minsuf[100005],maxpre[100005],maxsuf[100005];
pll a[100005];

bool check(ll x){
//	cout<<"check "<<x<<endl;
	for(int i=1;i<=n;i++){
		if(a[i].fi<0){
			int pl=lower_bound(a+1,a+n+1,mp(min(-a[i].fi,a[i].fi+(int)sqrt(x)),1ll<<60))-a-1;
			ll lf=min(minpre[i-1],minsuf[pl+1]),rg=max(maxpre[i-1],maxsuf[pl+1]);
			bool fl=1;
			if(lf!=minsuf[0]&&rg!=maxsuf[0]&&(rg-lf)*(rg-lf)>x) fl=0;
			if(lf!=minsuf[0]&&lf*lf+a[i].fi*a[i].fi>x) fl=0;
			if(rg!=maxsuf[0]&&rg*rg+a[i].fi*a[i].fi>x) fl=0;
//			if(fl) cout<<i<<' '<<pl<<' '<<lf<<' '<<rg<<' '<<a[i].fi<<' '<<a[pl].fi<<endl;
			if(fl) return true;
		}
		else{
			int pl=lower_bound(a+1,a+n+1,mp(max(-a[i].fi,a[i].fi-(int)sqrt(x)),-(1ll<<60)))-a;
			ll lf=min(minpre[pl-1],minsuf[i+1]),rg=max(maxpre[pl-1],maxsuf[i+1]);
			bool fl=1;
			if(lf!=minsuf[0]&&rg!=maxsuf[0]&&(rg-lf)*(rg-lf)>x) fl=0;
			if(lf!=minsuf[0]&&lf*lf+a[i].fi*a[i].fi>x) fl=0;
			if(rg!=maxsuf[0]&&rg*rg+a[i].fi*a[i].fi>x) fl=0;
//			if(fl) cout<<pl<<' '<<i<<' '<<lf<<' '<<rg<<' '<<a[pl].fi<<' '<<a[i].fi<<endl;
			if(fl) return true;
		}
	}
	return false;
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i].fi=readint(),a[i].se=readint();
	sort(a+1,a+n+1);
	memset(minpre,0x3f,sizeof(minpre));
	memset(minsuf,0x3f,sizeof(minsuf));
	memset(maxpre,-0x3f,sizeof(maxpre));
	memset(maxsuf,-0x3f,sizeof(maxsuf));
	for(int i=1;i<=n;i++) minpre[i]=min(minpre[i-1],a[i].se),maxpre[i]=max(maxpre[i-1],a[i].se);
	for(int i=n;i>=1;i--) minsuf[i]=min(minsuf[i+1],a[i].se),maxsuf[i]=max(maxsuf[i+1],a[i].se);
//	cout<<n<<endl;
//	for(int i=1;i<=n;i++) cout<<a[i].fi<<' '<<a[i].se<<endl;
	ll l=0,r=1000000000000000000ll,ans=0;
	while(l<=r){
		ll mid=(l+r)/2;
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",min(ans,(maxpre[n]-minpre[n])*(maxpre[n]-minpre[n])));
	return 0;
}