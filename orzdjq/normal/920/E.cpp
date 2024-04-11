#include<bits\stdc++.h>
using namespace std;
#define LL long long
#define ll   long long
#define ull unsigned long long
#define ULL ull
#define mp make_pair
#define pii pair<int,int>
#define piii pair<int, pii >
#define pll pair <ll,ll>
#define pb push_back
#define PB pop_back
#define p push
#define P pop
#define INF 2147483647
#define ull unsigned long long
#define vi vector < int >
#define vpii vector < pii >
#define pq priority_queue
#define rep(i,n) for (int (i)=0;(i)<n;(i)++)
#define End return 0
#define mi multiset <int>
#define si set <int>
#define sll set<ll>
#define mll multiset<ll>
#define vll vector <ll>
#define Rep(i,a,b) for (int (i)=(a);(i)<=(b);(i)++)
const int Maxn=200005;
int a[Maxn];
vector<int> G[Maxn],GG[Maxn];
bool adj[5005][5005];
int ex[Maxn],ey[Maxn];
vector<int> ans;
bool bad[Maxn];
map<pair<int,int>,bool> ff;
int cur;
int n,m;
bool vis[Maxn];
void dfs(int x){
	cur++;
	vis[x]=true;
	for (int i=1;i<=n;i++){
		if (adj[x][i] && !vis[i]) dfs(i);
	}
}
bool good;
void dfs2(int x){
	//if (!good) return;
	
	cur++;
	vis[x]=true;
	if (bad[x]){
		good=false;
		return;
	}
	for (int i=0;i<GG[x].size();i++){
		if (!vis[GG[x][i]]){
			dfs2(GG[x][i]);
		}
	}
}
int main(){

	scanf("%d %d",&n,&m);
	for (int i=0;i<m;i++){
		scanf("%d %d",&ex[i],&ey[i]);
		G[ex[i]].pb(ey[i]);
		G[ey[i]].pb(ex[i]);
		ff[mp(ex[i],ey[i])]=true;
		ff[mp(ey[i],ex[i])]=true;
	}
	if (n<=5000){
		for (int i=0;i<m;i++){
			adj[ex[i]][ey[i]]=adj[ey[i]][ex[i]]=true;
		}
		for (int i=1;i<=n;i++){
			adj[i][i]=true;
		}
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				adj[i][j]=!adj[i][j];
			}
		}
		for (int i=1;i<=n;i++){
			if (!vis[i]) cur=0,dfs(i),ans.pb(cur); 
		}
		sort(ans.begin(),ans.end());
		printf("%d\n",ans.size());
		for (int i=0;i<ans.size();i++){
			printf("%d ",ans[i]);
		}
		return 0;
	} 
	for (int i=1;i<=n;i++){
		if ((n-1)-G[i].size()>=50) bad[i]=true;
		else{
			for (int j=1;j<=n;j++){
				if (i!=j &&!ff.count(mp(i,j))) GG[i].pb(j);
			}
		}
	}
	int tot=n;
	for (int i=1;i<=n;i++){
		if (!bad[i] && !vis[i]){
			cur=0;good=true;dfs2(i);
			if (good)ans.pb(cur),tot-=cur;
		}
	}
	ans.pb(tot);
	sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	for (int i=0;i<ans.size();i++){
		printf("%d ",ans[i]);
	}
	return 0;
}