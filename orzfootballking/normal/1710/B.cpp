#include<bits/stdc++.h>
#define int long long
#define lb long double
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
int n,m;
P<P<int,int>,int> it[200005];
P<int,int> p[200005];
int val[200005],mx[200005],ans[200005];
void solve(){
	cin>>n>>m;
	FOR(i,1,n)cin>>it[i].F.F>>it[i].F.S,it[i].S=i;
	sort(it+1,it+n+1);
	FOR(i,1,n)p[i]=it[i].F;
	int sum=0,cnt=0;
	multiset<int> s;
	FOR(i,1,n){
		s.emplace(p[i].F+p[i].S);sum+=p[i].F+p[i].S;cnt++; 
		while(!s.empty()&&(*s.begin())<p[i].F){
			sum-=(*s.begin());
			cnt--;
			s.erase(s.begin());
		}
		val[i]=sum-p[i].F*cnt;
	}
	while(!s.empty())s.erase(s.begin());
	sum=cnt=0;
	for(int i=n;i>=1;i--){
		while(!s.empty()&&(*s.begin())<-p[i].F){
			sum+=(*s.begin());
			cnt--;
			s.erase(s.begin());
		}
		val[i]+=p[i].F*cnt-sum;
		s.emplace(-p[i].F+p[i].S);sum+=p[i].F-p[i].S;cnt++; 
	}
	mx[0]=-1e18;
	FOR(i,1,n)ans[i]=1;
	FOR(i,1,n){
		mx[i]=mx[i-1];
		if(val[i]>m)gmax(mx[i],val[i]-p[i].F);
		if(mx[i]+p[i].F-p[i].S>m)ans[it[i].S]=0;
	}
	mx[n+1]=-1e18;
	for(int i=n;i>=1;i--){
		mx[i]=mx[i+1];
		if(val[i]>m)gmax(mx[i],val[i]+p[i].F);
		if(mx[i]-p[i].F-p[i].S>m)ans[it[i].S]=0;
	}
	FOR(i,1,n)cout<<ans[i];
	cout<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}