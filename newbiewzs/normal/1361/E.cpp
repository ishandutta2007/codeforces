#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
#include<ctime>
#include<bitset>
#include<set>
#define ui unsigned
#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
#define pil pair<int,long long>
#define pll pair<long long,long long>
#define vi vector<int>
#define vl vector<long long>
#define ci ios::sync_with_stdio(false)
//#define int long long
using namespace std;
typedef long long ll;
const int N=1e5+55;
int T,n,m,x,y,tot,cn=0;
vi v[N],g[N];
bool vis[N],bj[N*2];
int deep[N],siz[N],top[N],son[N],fu[N],faa[N];
void dfs(int u,int fa){
	vis[u]=1;deep[u]=deep[fa]+1;siz[u]=1;fu[u]=faa[u]=fa;
	for(ui int i=0;i<v[u].size();i++){
		if(vis[v[u][i]])continue;
		bj[g[u][i]]=1;
		dfs(v[u][i],u);
		siz[u]+=siz[v[u][i]];
		if(siz[v[u][i]]>siz[son[u]])son[u]=v[u][i];
	}
}
void dfs1(int u,int fa){
	top[u]=fa;
	if(son[u])dfs1(son[u],fa);
	for(ui int i=0;i<v[u].size();i++){
		if(top[v[u][i]])continue;
		if(!bj[g[u][i]])continue;
		dfs1(v[u][i],v[u][i]);
	}
}
int lca(int x,int y){
	while(top[x]!=top[y]){
		if(deep[top[x]]<deep[top[y]])swap(x,y);
		x=fu[top[x]];
	}
	if(deep[x]<deep[y])swap(x,y);return y;
}
bool check(int u){
	for(int i=1;i<=tot;i++)bj[i]=0;
	for(int i=1;i<=n;i++)vis[i]=0,siz[i]=son[i]=top[i]=0;
	dfs(u,0);
	dfs1(u,u);
	for(int i=1;i<=n;i++){
		for(int k=0;k<v[i].size();k++){
			if(!bj[g[i][k]] and lca(v[i][k],i)!=v[i][k]){
				return 0;
			}
		}
	}
	return 1;
}
vector<int>cd[N];
bool flag[N];
int st[N],head,p[N];
void calc(int u){
	
	for(int i=0;i<v[u].size();i++){
		if(bj[g[u][i]]){
			calc(v[u][i]);
			for(int k=0;k<cd[v[u][i]].size();k++){
				if(cd[v[u][i]][k]!=u){
					cd[u].pb(cd[v[u][i]][k]);
				}
			}
		}
		else cd[u].pb(v[u][i]);
	}
	if(cd[u].size()>1)flag[u]=0;
}
void dfss(int u){
	if(cd[u].size()==1)flag[u]&=flag[cd[u][0]];
	if(flag[u])st[++head]=u;
	for(int i=0;i<v[u].size();i++){
		if(bj[g[u][i]]){
			dfss(v[u][i]);
		}
	}
}
int gg;
void solve(){
	for(int i=1;i<=n;i++)cd[i].clear(),flag[i]=1;head=0;
	for(int i=1;i<=n;i++)p[i]=i;
	random_shuffle(p+1,p+n+1);
	for(int i=1;i<=100;i++){
		int x=p[i];
		if(!p[i])break;
		if(check(x)){
			calc(x);
			dfss(x);
			if(head*5<n){
				puts("-1");return ;
			}
			sort(st+1,st+head+1);
			for(int k=1;k<=head;k++){
				printf("%d ",st[k]);
			}
			puts("");
			return ;
		}
	}
	puts("-1");return ;
}
int main(){
	srand(time(0));
	cin>>T;
	gg=T;
	while(T--){
	//	cn++;
		if(cn==78){
			cin>>n>>m;
			cout<<n<<" "<<m<<endl;
			for(int i=1;i<=m;i++){
				cin>>x>>y;
				cout<<x<<" "<<y<<endl;
			}
			return 0;
		}
		tot=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			v[x].pb(y);
			tot++;
			g[x].pb(tot);
		}
		//if(gg<=10){
			solve();
			for(int i=1;i<=n;i++){
				v[i].clear();
				g[i].clear();
			}
		//}
		for(int i=1;i<=tot;i++){
			bj[i]=0;
		}
	}
	return 0;
}
/*
2
4 6
2 1
1 3
1 2
4 2
3 4
2 4

4 8
4 3
1 3
1 2
3 1
1 4
2 1
4 1
3 2
*/