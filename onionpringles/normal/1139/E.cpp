#include <bits/stdc++.h>
using namespace std;
const int N=5010;
vector<int> adj[N];
int mat[N],chk[N],c[N],p[N],di[N],ans[N];
bool Do(int u){
	chk[u]=1;
	for(auto &x:adj[u]){
		if(mat[x]==-1||!chk[mat[x]]&&Do(mat[x])){
			mat[x]=u;return true;
		}
	}
	return false;
}
int main(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)mat[i]=-1;
	for(int i=0;i<n;i++)scanf("%d",p+i);
	for(int i=0;i<n;i++)scanf("%d",c+i),c[i]--;
	int d;scanf("%d",&d);
	for(int i=0;i<d;i++){
		scanf("%d",di+i);di[i]--;
		chk[di[i]]=1;
	}
	for(int i=0;i<n;i++){
		if(chk[i])continue;
		adj[p[i]].push_back(c[i]);
	}
	int cur=0;
	while(1){
		memset(chk,0,sizeof(chk));
		if(Do(cur)){
			cur++;continue;
		}
		else break;
	}
	ans[d]=cur;
	for(int i=d;i--;){
		int j=di[i];
		adj[p[j]].push_back(c[j]);
		while(1){
			memset(chk,0,sizeof(chk));
			if(Do(cur)){
				cur++;continue;
			}
			else break;
		}
		ans[i]=cur;
	}
	for(int i=1;i<=d;i++)printf("%d\n",ans[i]);
	
}