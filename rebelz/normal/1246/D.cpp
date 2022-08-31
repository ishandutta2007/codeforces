#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,cnt,lw;
int ans[100005],dep[100005];
bool fn[100005];
vector<int> adj[100005],opt;

void dfs1(int u){
	for(auto v:adj[u]){
		dep[v]=dep[u]+1;
		dfs1(v);
	}
}

void dfs2(int u){
	fn[u]=u==lw;
	for(auto v:adj[u]){
		dfs2(v);
		fn[u]|=fn[v];
	}
}

void dfs3(int u){
	ans[++cnt]=u;
	if(!adj[u].size()) return;
	for(int i=0;i<adj[u].size();i++){
		if(fn[adj[u][i]]){
			swap(adj[u][0],adj[u][i]);
			break;
		}
	}
	for(int i=0;i<adj[u].size()-1;i++) adj[adj[u][i+1]].push_back(adj[u][i]),opt.push_back(adj[u][i]),fn[adj[u][i+1]]=1;
	dfs3(adj[u][adj[u].size()-1]);
}

int main(){
	n=readint();
	for(int i=2;i<=n;i++) adj[readint()+1].push_back(i);
	dep[1]=1; dfs1(1);
	int tmp=0;
	for(int i=1;i<=n;i++) if(chkmax(tmp,dep[i])) lw=i;
	dfs2(1);
	dfs3(1);
	for(int i=1;i<=n;i++) printf("%d ",ans[i]-1);
	printf("\n%d\n",opt.size());
	for(int i=opt.size()-1;i>=0;i--) printf("%d ",opt[i]-1);
	printf("\n");
	return 0;
}