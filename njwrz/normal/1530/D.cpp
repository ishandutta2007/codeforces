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
int n,a[200005],in[200005],b[200005],vis[200005];
V<int> lst;
void dfs(int x){
//	cout<<x<<' ';
	if(vis[x])RE;
	vis[x]=1;
	in[a[x]]--;lst.PB(x);
	if(in[a[x]]==0)dfs(a[x]);
}
void solve(){
	cin>>n;lst.clear();
	FOR(i,1,n)in[i]=0,vis[i]=0;
	FOR(i,1,n)cin>>a[i],in[a[i]]++;
	FOR(i,1,n)if(!in[i])dfs(i);
//	cout<<'\n';
	int t=0,to;
	if(!lst.empty()){
		to=a[lst.back()];
	}
	if(!lst.empty()){
		reverse(ALL(lst));
		FOR(i,1,n){
			if(in[i]){
				b[i]=a[i];if(a[i]==to)t=i;
			}
		}
		while(!lst.empty()){
			b[t]=lst.back();
			t=lst.back();lst.pop_back();
		}
		b[t]=to;
	}else FOR(i,1,n)b[i]=a[i];
	int ans=0;
	FOR(i,1,n)ans+=b[i]==a[i];
	cout<<ans<<'\n';
	FOR(i,1,n)cout<<b[i]<<' ';cout<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}