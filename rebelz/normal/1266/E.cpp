#include<bits/stdc++.h>

#define y1 dmytxdy
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

int n,q; ll ans;
int a[200005],cnt[200005];
set<pii> s[200005];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint(),ans+=a[i];
	q=readint();
	ll x,y,z;
	while(q--){
		x=readint(); y=readint(); z=readint();
		auto it=s[x].lower_bound(mp(y,0));
		if(it!=s[x].end()&&it->fi==y){
			ans-=max(a[it->se]-cnt[it->se],0);
			cnt[it->se]--;
			ans+=max(a[it->se]-cnt[it->se],0);
			s[x].erase(it);
		}
		if(z){
			ans-=max(a[z]-cnt[z],0);
			cnt[z]++;
			ans+=max(a[z]-cnt[z],0);
			s[x].insert(mp(y,z));
		}
		printf("%lld\n",ans);
	}
	return 0;
}