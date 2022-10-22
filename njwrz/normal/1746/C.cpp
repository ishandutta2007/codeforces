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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
#define sz(x) ((int)x.size())
using namespace std;
int n,a[100005],ans[100005];
void solve(){
	cin>>n;
	priority_queue<P<int,int> > q;
	FOR(i,1,n)cin>>a[i];
	rep(i,1,n)q.emplace(MP(a[i]-a[i+1],i));
	if(n==1){
		cout<<1<<'\n';RE;
	}
	for(int i=n;i>=1;i--){
		P<int,int> now=q.top();q.pop();
		ans[i]=now.S+1;
		now.F-=i;
	}
	FOR(i,1,n)cout<<ans[i]<<' ';
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