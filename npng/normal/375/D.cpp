#include <cstdio>
#include <vector>
#define Maxn int(1e5)
using namespace std;
typedef pair<int,int> Pair;
struct Node{
	int to,nxt;
}Edge[(Maxn<<1)+5];
int tot,Head[Maxn+5];
void Addedge(int x,int y){
	Edge[++tot].to=y;
	Edge[tot].nxt=Head[x];
	Head[x]=tot;
}
vector<Pair> q[Maxn+5];
int n,m,col[Maxn+5],ans[Maxn+5];
int siz[Maxn+5],son[Maxn+5];
int cnt[Maxn+5],sum[Maxn+5];
void predfs(int x,int f){
	siz[x]=1;
	for(int i=Head[x];i;i=Edge[i].nxt){
		int y=Edge[i].to;
		if(y==f){
			continue;
		}
		predfs(y,x);
		siz[x]+=siz[y];
		if(siz[y]>siz[son[x]]){
			son[x]=y;
		}
	}
}
int flag;
void Count(int x,int f,int k){
	if(k==1){
		sum[cnt[col[x]]+k]++;
	}
	if(k==-1){
		sum[cnt[col[x]]]--;
	}
	cnt[col[x]]+=k;
	for(int i=Head[x];i;i=Edge[i].nxt){
		int y=Edge[i].to;
		if(y==f||y==flag){
			continue;
		}
		Count(y,x,k);
	}
}
void dfs(int x,int f,int typ){
	for(int i=Head[x];i;i=Edge[i].nxt){
		int y=Edge[i].to;
		if(y==f||y==son[x]){
			continue;
		}
		dfs(y,x,0);
	}
	if(son[x]){
		dfs(son[x],x,1);
		flag=son[x];
	}
	Count(x,f,1);
	flag=0;
	for(int i=0;i<q[x].size();i++){
		int y=q[x][i].first;
		ans[q[x][i].second]=sum[y];
	}
	if(typ==0){
		Count(x,f,-1);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",&col[i]);
	}
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		Addedge(a,b);
		Addedge(b,a);
	}
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		q[a].push_back(make_pair(b,i));
	}
	predfs(1,0);
	dfs(1,0,0);
	for(int i=1;i<=m;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}