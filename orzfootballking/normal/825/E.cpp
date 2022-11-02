#pragma GCC optimize("Ofast")
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
V<int> v[100005];
int n,m,in[100005],ans[100005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x,y;
	cin>>n>>m;
	FOR(i,1,m){
		cin>>x>>y;
		v[y].PB(x);
		in[x]++;
	}
	int now=n;
	priority_queue<int> q;
	FOR(i,1,n)if(!in[i])q.emplace(i);
	int cur;
	while(!q.empty()){
		cur=q.top();ans[cur]=now--;q.pop();
		for(auto u:v[cur])if(--in[u]==0)q.emplace(u);
	}
	FOR(i,1,n)cout<<ans[i]<<' ';
	RE 0;
}