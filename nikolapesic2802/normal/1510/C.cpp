#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int,int>
#define ll long long

const int N=100050;
int n,k,m;
vector<pii> edges;
vector<bool> use;//,blk;
vector<pii> E[N];
set<int> T[N];
void AddEdge(int u,int v,int i){
	edges.pb({u,v});
	E[u].pb({v,i});
	E[v].pb({u,i});
}
bool was1[N];
int pe[N],par[N],dep[N];
void DFS1(int u,int p){
	was1[u]=true;
	for(pii e:E[u])if(e.second!=p){
		if(was1[e.first]&&dep[e.first]<dep[u]){
			use[e.second-1]=false;
			for(int v=u;v!=e.first;v=par[v])use[pe[v]-1]=false;
		}else if(!was1[e.first]){
			par[e.first]=u;
			pe[e.first]=e.second;
			dep[e.first]=dep[u]+1;
			DFS1(e.first,e.second);
		}
	}
}
void BuildForest(){
	use.assign(m,true);
	DFS1(1,0);
	for(int i=0;i<m;i++)if(use[i]){
		int u,v;
		tie(u,v)=edges[i];
		T[u].insert(v);
		T[v].insert(u);
	}
}
#define E ???

vector<pii> ans;
/*bool was2[N],is_leaf[N],mark[N];
vector<int> undo_leaf,leaf_arr;
int leaf_cnt;
int chsz[N];
void DFS2(int u,bool is_root=true){
	int ch=0;
	was2[u]=true;
	mark[u]=true;
	vector<int> leafs;
	for(int v:T[u])if(!was2[v]){
		par[v]=u;
		DFS2(v,false);
		ch++;
		if(is_leaf[v])leafs.pb(v);
	}
	chsz[u]=ch;
	if(ch==0){
		is_leaf[u]=true;
		leaf_cnt++;
		leaf_arr.pb(u);
	}else if((!is_root&&ch>1)||ch>2){
		if(leafs.size()){
			mark[leafs[0]]=false;
			undo_leaf.pb(leafs[0]);
			leaf_cnt--;
		}
	}
}*/
/*int sz[N];
void DFSSZ(int u,int p){
	sz[u]=0;
	for(int v:T[u])if(v!=p){
		DFSSZ(v,u);
		sz[u]+=sz[v];
	}
	if(sz[u]==0)sz[u]=1;
}
int FindCen(int u,int p,int n){
	for(int v:E[u]){
		if(v!=p&&sz[v]*2>n)return FindCen(v,u,n);
	}
	return u;
}*/
/*vector<int> ord;
void DFS3(int u,int p){
	if(is_leaf[u])ord.pb(u);
	for(int v:T[u])if(v!=p&&mark[v])DFS3(v,u);
}*/

vector<int> nodes;
int dp[N][2],go[N];//,deg[N];
bool was2[N];
void DP(int u,int p){
	int odd=T[u].size()%2==1;
	int best=0,it=0;
	for(int v:T[u])if(v!=p){
		DP(v,u);
		int oddv=T[v].size()%2==1;
		dp[u][0]+=max(dp[v][1],dp[v][0]);
		if(odd&&oddv){
			best=max(best,dp[v][0]-max(dp[v][1],dp[v][0])+1);
			if(best==dp[v][0]-max(dp[v][1],dp[v][0])+1)it=v;
		}
	}
	dp[u][1]=dp[u][0]+best;
	go[u]=it;
	//deg[u]=T[u].size();
	nodes.pb(u);
	was2[u]=true;
}
void Rec(int u,int p,int t){
	if(t==0||go[u]==0){
		for(int v:T[u])if(v!=p){
			Rec(v,u,1);
		}
	}else{
		for(int v:T[u])if(v!=p){
			if(v==go[u]){
				Rec(v,u,0);
			}else{
				Rec(v,u,1);
			}
		}
		T[u].erase(go[u]);
		T[go[u]].erase(u);
	}
}
int GO(int u){
	int h=*T[u].begin();
	T[u].erase(h);
	T[h].erase(u);
	if(T[h].size()%2==0)return h;
	return GO(h);
}

void SolveTree(int root){
	nodes.clear();
	DP(root,0);
	Rec(root,0,1);
	for(int u:nodes){
		if(T[u].size()%2==1){
			int v=GO(u);
			ans.pb({u,v});
		}
	}
	/*undo_leaf.clear();
	leaf_arr.clear();
	leaf_cnt=0;
	DFS2(root);
	if(leaf_cnt%2==1){
		if(undo_leaf.size()){
			mark[undo_leaf[0]]=true;
			leaf_cnt++;
		}else{
			for(int leaf:leaf_arr){
				if(chsz[par[leaf]]==1){
					int v=leaf;
					while(chsz[v]<=1){
						mark[v]=false;
						v=par[v];
					}
					ans.pb({leaf,v});
					leaf_cnt--;
					break;
				}
			}
		}
	}
	ord.clear();
	DFS3(root,0);
	assert(ord.size()==leaf_cnt);
	for(int i=0;i<leaf_cnt/2;i++){
		ans.pb({ord[i],ord[i+leaf_cnt/2]});
	}*/
}

void SolveForest(){
	//blk.assign(m,false);
	for(int i=1;i<=n;i++)if(!was2[i]&&T[i].size()>1){
		SolveTree(i);
	}
}

#undef E
bool Solve(){
	scanf("%i %i",&n,&k);
	if(n==0)return false;

	for(int i=1;i<=k;i++){
		int s;
		scanf("%i",&s);
		vector<int> nodes(s);
		for(int j=0;j<s;j++){
			scanf("%i",&nodes[j]);
			if(j>0)AddEdge(nodes[j-1],nodes[j],++m);
		}
	}
	assert(m==edges.size());
	//printf(":D\n");
	BuildForest();

	SolveForest();
	printf("%i\n",ans.size());
	for(pii e:ans)printf("%i %i\n",e.first,e.second);

	for(int i=1;i<=n;i++){
		E[i].clear();
		T[i].clear();
		was1[i]=false;
		was2[i]=false;
		//is_leaf[i]=false;
		//chsz[i]=0;
		pe[i]=0;
		par[i]=0;
		dep[i]=0;
		dp[i][0]=dp[i][1]=0;
		go[i]=0;
	}
	edges.clear();
	use.clear();
	//blk.clear();
	m=0;
	ans.clear();
	return true;
}
int main(){
	while(Solve());
	return 0;
}