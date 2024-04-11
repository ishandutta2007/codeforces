#include<bits/stdc++.h>
#define LL long long
#define maxn 100010
#define mo 1000000007
#define inf 10000000000000000LL
#define eps 1e-6
using namespace std;
struct region{
	LL sum;
	int col;
}r[maxn];
int n,m,tot,num[4*maxn],cnt,siz[maxn];
vector<pair<int,int> > edge[maxn];
vector<int> b[maxn],g[maxn];
int cmp(region x,region y){
	return x.sum<y.sum;
}
void dfs(int x,int y){
	g[cnt].push_back(x);
	int i=(lower_bound(edge[y].begin(),edge[y].end(),make_pair(x,0))-edge[y].begin()-1+edge[y].size())%edge[y].size();
	if (num[edge[y][i].second]) return;
	num[edge[y][i].second]=cnt;
	dfs(y,edge[y][i].first);
}
void dfs1(int x,int y){
	siz[x]=1;
	for (int i=0;i<b[x].size();i++)
	if (b[x][i]!=y&&(!r[b[x][i]].col)){
		dfs1(b[x][i],x);
		siz[x]+=siz[b[x][i]];
	}
}
int get(int x,int y,int z){
	for (int i=0;i<b[x].size();i++)
	if (b[x][i]!=y&&(!r[b[x][i]].col)&&2*siz[b[x][i]]>z) return get(b[x][i],x,z);
	return x;
}
void dfs2(int x,int y){
	dfs1(x,0);
	int tmp=get(x,0,siz[x]);
	r[tmp].col=y;
	for (int i=0;i<b[tmp].size();i++)
	if (!r[b[tmp][i]].col) dfs2(b[tmp][i],y+1);
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++){
    	int o,p;
		scanf("%d%d",&o,&p);
		edge[o].push_back(make_pair(p,tot++));
		edge[p].push_back(make_pair(o,tot++));
    }
    for (int i=1;i<=n;i++){
		edge[i].push_back(make_pair(i%n+1,tot++));
		edge[i%n+1].push_back(make_pair(i,tot++));
    }
    for (int i=1;i<=n;i++) sort(edge[i].begin(),edge[i].end());
	for (int i=1;i<=n;i++)
	for (int j=0;j<edge[i].size();j++)
	if (!num[edge[i][j].second]){
		num[edge[i][j].second]=++cnt;
		dfs(i,edge[i][j].first);
	}
	for (int i=0;i<2*m;i++) b[num[i]].push_back(num[i^1]);
	for (int i=1;i<=cnt;i++) sort(g[i].begin(),g[i].end());
	for (int i=1;i<=cnt;i++){
		for (int j=1;j<4;j++){
			r[i].sum*=maxn;
			r[i].sum+=g[i][g[i].size()-j];
		}
	}
	dfs2(1,1);
	sort(r+1,r+cnt+1,cmp);
	for (int i=1;i<=cnt;i++)
	if (r[i].col) printf("%d ",r[i].col);
}