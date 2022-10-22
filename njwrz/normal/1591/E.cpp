#include<bits/stdc++.h>
#define ll long long
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
int cnt[1000005];
set<int> s[1000005];
int n;
V<int> q[1000005],v[1000005];
int m,l[1000005],num[1000005],ans[1000005],a[1000005];
int sum[1000005];
void update(int x,int y){
	while(x<=n+1){
		sum[x]+=y;
		x+=x&-x;
	}
}
int get(int x){
	int re=0;
	while(x){
		re+=sum[x];
		x-=x&-x;
	}
	RE re;
}
int get2(int x){
	int re=0;
	for(int i=19;i>=0;i--){
		if(re+(1<<i)<=n+1&&x>sum[re+(1<<i)]){
			x-=sum[re+(1<<i)];
			re+=(1<<i);
		}
	}
	RE re+1;
}
void dfs(int x,int y){
	update(cnt[a[x]]+1,-1);
	s[cnt[a[x]]+1].erase(a[x]);
	cnt[a[x]]++;
	update(cnt[a[x]]+1,1);
	s[cnt[a[x]]+1].emplace(a[x]);
	for(auto u:q[x]){
		int t=get(l[u]);
		ans[u]=get2(t+num[u]);
		if(s[ans[u]].empty()){
			ans[u]=-1;
		}else ans[u]=*s[ans[u]].begin();
	}
	for(auto u:v[x]){
		dfs(u,x);
	}
	update(cnt[a[x]]+1,-1);
	s[cnt[a[x]]+1].erase(a[x]);
	cnt[a[x]]--;
	update(cnt[a[x]]+1,1);
	s[cnt[a[x]]+1].emplace(a[x]);
}
void solve(){
	cin>>n>>m;
	FOR(i,1,n)cin>>a[i],v[i].clear(),q[i].clear(),cnt[i]=0;
	FOR(i,2,n){
		int x;
		cin>>x;
		v[x].PB(i);
	}
	FOR(i,1,n)s[1].emplace(i);
	update(1,n);
	FOR(i,1,m){
		int x;
		cin>>x;
		cin>>l[i]>>num[i];
		q[x].PB(i);
	}
	dfs(1,-1);
	update(1,-n);
	FOR(i,1,n)s[i].clear();
	FOR(i,1,m){
		cout<<ans[i]<<' ';
	}
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