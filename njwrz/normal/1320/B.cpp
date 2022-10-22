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
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
V<int> v[200005],fv[200005];
int n,p[200005],k,d[200005];
void bfs(){
	queue<int> q;
	q.emplace(p[k]);
	FILL(d,0x3f);
	d[p[k]]=0;
	int cur;
	while(!q.empty()){
		cur=q.front();
		q.pop();
		for(auto u:fv[cur]){
			if(d[u]>d[cur]+1){
				d[u]=d[cur]+1;
				q.emplace(u);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m;
	cin>>n>>m;
	int x,y;
	FOR(i,1,m){
		cin>>y>>x;
		fv[x].PB(y);v[y].PB(x);
	}
	cin>>k;
	FOR(i,1,k){
		cin>>p[i];
	}
	bfs();
	int maxi=0,mini=0,cnt;
	rep(i,1,k){
		cnt=0;
		for(auto u:v[p[i]])cnt+=(d[u]==d[p[i]]-1);
		mini+=(d[p[i+1]]!=d[p[i]]-1);
		maxi+=((cnt>1)||(d[p[i+1]]!=d[p[i]]-1));
	}
	cout<<mini<<' '<<maxi<<'\n';
	RE 0;
}