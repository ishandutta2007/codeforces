#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<char> g[1000007];
char tmp[1000007];
int fa[1000007][21];
bool vis[1000007];
int dep[1000007];
void add(int u,int v){
	vis[v]=true;
	dep[v]=dep[u]+1;
	fa[v][0]=u;
	for(int i=1;i<=20;i++){
		fa[v][i]=fa[fa[v][i-1]][i-1];
	}
}
int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(int i=20;i>=0;i--){
		if((dep[u]-dep[v])&(1<<i))u=fa[u][i];
	}
	if(u==v)return u;
	for(int i=20;i>=0;i--){
		if(fa[u][i]!=fa[v][i]){
			u=fa[u][i],v=fa[v][i];
		}
	}
	return fa[u][0];
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		scanf("%s",tmp);
		for(int j=0;j<m;j++){
			g[i].push_back(tmp[j]);
		}
	}
	vis[1]=true;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int u=i*m+j+1;
			if(g[i][j]=='#')continue;
			else {
				int v=0,w=0;
				if(i>0&&g[i-1][j]=='.')v=(i-1)*m+j+1;
				if(j>0&&g[i][j-1]=='.')w=i*m+j;
				if(!vis[v])v=0;
				if(!vis[w])w=0;
				if(!v&&!w)continue;
				if(v&&w){
					add(lca(v,w),u);
				}
				else if(v){
					add(v,u);
				}
				else if(w){
					add(w,u);
				}
			}
		}
	}
	if(!vis[n*m])cout<<0<<endl;
	else if(fa[n*m][0]==1)cout<<2<<endl;
	else cout<<1<<endl;
}