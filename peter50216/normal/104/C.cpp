#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
int pre[110];
vector<int> ed[110];
inline int find(int a){return pre[a]==-1?a:pre[a]=find(pre[a]);}
int w[110],wc=0;
bool vis[110];
bool onc[110];
inline int dfs(int np,int p){
    int i;
    vis[np]=1;
    for(i=0;i<ed[np].size();i++){
	int y=ed[np][i];
	if(y==p)continue;
	if(vis[y]){
	    onc[np]=1;
	    return y;
	}
	int r=dfs(y,np);
	if(r!=-1){
	    onc[np]=1;
	    if(r==np)return -1;
	    return y;
	}
    }
    return -1;
}
int main(){
    int n,m,i;
    scanf("%d%d",&n,&m);
    if(m!=n){
	puts("NO");
	return 0;
    }
    memset(pre,-1,sizeof(pre));
    for(i=0;i<m;i++){
	int a,b;
	scanf("%d%d",&a,&b);
	a--;b--;
	ed[a].push_back(b);
	ed[b].push_back(a);
	a=find(a);b=find(b);
	if(a!=b)pre[a]=b;
    }
    for(i=0;i<n;i++)if(find(i)!=find(0))break;
    if(i<n){
	puts("NO");
	return 0;
    }
    dfs(0,-1);
    int cnt=0;
    for(i=0;i<n;i++)if(onc[i])cnt++;
    if(cnt>=3)puts("FHTAGN!");
    else puts("NO");
}