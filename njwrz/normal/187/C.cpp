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
int d[100005];
bool f[100005];
V<int> v[100005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,k,x,y;
	cin>>n>>m>>k;
	FOR(i,1,k){
		cin>>x;f[x]=1;
	}
	FOR(i,1,m){
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	int s,t;
	cin>>s>>t;
	priority_queue<P<int,int>,V<P<int,int>>,greater<P<int,int>>> q;
	q.emplace(0,s);
	FOR(i,1,n)d[i]=1e9;
	d[s]=0;
	int ans=0;
	P<int,int> cur;
	while(!q.empty()){
		cur=q.top();q.pop();
		if(cur.F>d[cur.S])continue;
		gmax(ans,d[cur.S]);
		if(cur.S==t){
			cout<<ans;RE 0;
		}
		if(f[cur.S])d[cur.S]=0;
		for(auto u:v[cur.S]){
			if(d[u]>d[cur.S]+1){
				d[u]=d[cur.S]+1;
				q.emplace(d[u],u);
			}
		}
	}
	cout<<-1;
	RE 0;
}