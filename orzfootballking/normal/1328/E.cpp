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
V<int> v[200005];
int n,fa[200005][20],de[200005];
const int N=17;
void dfs(int p){
	for(int u:v[p]){
		if(fa[p][0]==u)continue;
		fa[u][0]=p;de[u]=de[p]+1;
		dfs(u);
	}
}
bool cmp(int x,int y){
	RE de[x]<de[y];
}
bool check(int x,int y){
	int t=de[y]-de[x];
	FOR(i,0,N){
		if(t&(1<<i))y=fa[y][i];
	}
	RE (x==y);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m;
	cin>>n>>m;
	int x,y;
	rep(i,1,n){
		cin>>x>>y;
		v[x].PB(y);v[y].PB(x);
	}
	dfs(1);
	FOR(i,1,N){
		FOR(j,1,n)fa[j][i]=fa[fa[j][i-1]][i-1];
	}
	bool f;int l;
	FOR(i,1,m){
		cin>>x;V<int> q;
		FOR(j,1,x){
			cin>>y;
			if(y!=1)q.PB(fa[y][0]);
		}
		sort(ALL(q),cmp);
		f=1;
		l=q.size()-1;
		rep(j,0,l){
			if(!check(q[j],q[j+1])){
				f=0;break;
			}
		}
		cout<<(f?"YES\n":"NO\n");
	}
	RE 0;
}