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

int n,k;
ll a[100005],now[100005];

ll sqr(ll x){return x*x;}

ll f(ll t,ll h){
	ll g=h+1,r=t%(h+1);
	return r*sqr((t-1)/g+1)+(g-r)*sqr(t/g);
}

int main(){
	n=readint(); k=readint();
	ll ans=0;
	for(int i=1;i<=n;i++) a[i]=readint(),ans+=a[i]*a[i];
	set<pll> s; s.clear();
	for(int i=1;i<=n;i++) if(a[i]>1) s.insert(mp(f(a[i],1)-f(a[i],0),i));
	for(int i=1;i<=k-n;i++){
		pll tmp=*s.begin();
		s.erase(tmp);
		ans+=tmp.fi;
		now[tmp.se]++;
		if(now[tmp.se]+1<a[tmp.se]) s.insert(mp(f(a[tmp.se],now[tmp.se]+1)-f(a[tmp.se],now[tmp.se]),tmp.se));
	}
	printf("%lld\n",ans);
	return 0;
}