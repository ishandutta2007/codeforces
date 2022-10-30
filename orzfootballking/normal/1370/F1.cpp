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
V<int> v[1005],q[1005];
int n,d[1005],fa[1005];
bool used[1005];
P<int,int> qus(V<int> v){
	putchar('?');
	int len=v.size();
	printf(" %d",len);
	for(auto u:v)printf(" %d",u);
	puts("");
	fflush(stdout);
	int id,dis;
	scanf("%d%d",&id,&dis);
	RE MP(id,dis);
}
void dfs(int id){
	q[d[id]].PB(id);
	for(auto u:v[id])if(u!=fa[id]){
		fa[u]=id;d[u]=d[id]+1;
		dfs(u);
	}
}
void solve(){
	scanf("%d",&n);
	FOR(i,0,n)v[i].clear(),q[i].clear(),used[i]=0;
	int x,y;
	rep(i,1,n){
		scanf("%d%d",&x,&y);
		v[x].PB(y);
		v[y].PB(x);
	}
	V<int> g;
	FOR(i,1,n)g.PB(i);
	P<int,int> f=qus(g);
	int root=f.F,dis=f.S;
	if(!dis){
		printf("! %d %d\n",root,root);
		fflush(stdout);
		string s;cin>>s;
		RE;
	}
	fa[root]=0;d[root]=0;
	dfs(root);
	int maxi=0;
	FOR(i,1,n)gmax(maxi,d[i]);
	int l=(dis+1)>>1,r=min(maxi,dis),mid,ans,start;
	while(l<=r){
		mid=(l+r)>>1;
		f=qus(q[mid]);
		if(f.S==dis){
			ans=mid;l=mid+1;start=f.F;
		}else r=mid-1;
	}
	g.clear();
	int t=start;
	while(t){
		used[t]=1;t=fa[t];
	}
	for(auto u:q[dis-ans])if(!used[u]||u==root)g.PB(u);
	f=qus(g);
	printf("! %d %d\n",start,f.F);
	string s;
	cin>>s;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)solve(); 
	RE 0;
}