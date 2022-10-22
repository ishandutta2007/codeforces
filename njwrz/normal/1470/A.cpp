#include<bits/stdc++.h>
#define int long long
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
using namespace std;
int cnt[300005],c[300005];
void solve(){
	int n,m;
	cin>>n>>m;
	FOR(i,1,n){
		cin>>cnt[i];
	}
	FOR(i,1,m)cin>>c[i];
	sort(cnt+1,cnt+n+1);
	priority_queue<int,V<int>,greater<int> > q;
	int ans=0;
	FOR(i,1,n){
		FOR(j,cnt[i-1]+1,cnt[i])q.emplace(c[j]);
		if(q.empty()||q.top()>c[cnt[i]]){
			ans+=c[cnt[i]];
		}else{
			ans+=q.top();
			q.pop();
			q.emplace(c[cnt[i]]);
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}