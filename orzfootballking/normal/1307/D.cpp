#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
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
using namespace std;
int n,d[2][200005];
V<int> v[200005];
V<P<int,int> > v1;
bool f[200005];
void bfs(int e,int p){
	priority_queue<P<int,int>,V<P<int,int> >,greater<P<int,int> > > q;
	q.emplace(MP(0,p));
	FILL(d[e],-1);
	P<int,int> cur;
	while(!q.empty()){
		cur=q.top();q.pop();
		if(d[e][cur.S]!=-1)continue;
		d[e][cur.S]=cur.F;
		for(auto u:v[cur.S]){
			if(d[e][u]==-1){
				q.emplace(MP(cur.F+1,u));
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m,k;
	cin>>n>>m>>k;
	int x,y;
	FOR(i,1,k){
		cin>>x;
		f[x]=1;
	}
	bool anf=1;
	FOR(i,1,m){
		cin>>x>>y;
		if(f[x]&&f[y])anf=0;
		v[x].PB(y);
		v[y].PB(x);
	}
	bfs(0,1);bfs(1,n);
	if(!anf){
		cout<<d[0][n];RE 0;
	}
	priority_queue<int> q;
	FOR(i,1,n){
		if(f[i]){
			v1.PB(MP(d[0][i],i));
		}
	}
	sort(ALL(v1),greater<P<int,int> >());
	int ans=0;
	for(auto u:v1){
		if(q.size()){
			ans=max(ans,u.F+1+q.top());
		}
		q.emplace(d[1][u.S]);
	}
	cout<<min(ans,d[0][n]);
	RE 0;
}