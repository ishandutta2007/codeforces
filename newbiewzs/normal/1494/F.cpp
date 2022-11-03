#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
const int N=3005;
int n,m,x,y,in[N],deg[N];
vector<int>v[N],g[N];
int stx[N*2],sty[N*2],top;
void add(int e,int r){
	v[e].push_back(r);
	in[r]++;
	stx[++top]=e;
	sty[top]=r;
}
bool pd[N][N],vis[N][N],bj[N][N];
int head,q[N],tem;
struct node{
	int next,to;
}a[N*2];
int headl[N],cn,zs;
void link(int e,int r){
	a[++cn].next=headl[e];
	a[cn].to=r;
	headl[e]=cn;
}
void eular(int u){
	for(int i=headl[u];i;i=a[i].next){
		headl[u]=i;
		if(bj[u][a[i].to] ||vis[u][a[i].to])continue;
		bj[u][a[i].to]=bj[a[i].to][u]=1;
		eular(a[i].to);
	}
	q[++head]=u;
}
bool check(int u){
	for(int i=1;i<=n;i++){
		deg[i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int k=0;k<g[i].size();k++){
			if(vis[i][g[i][k]])continue;
			deg[g[i][k]]++;
		}
	}
	int cnt=0;head=0;
	for(int i=1;i<=n;i++){
		if(deg[i]%2==1)cnt++;
	}
	if(cnt!=0 and cnt!=2)return 0;
	if(cnt==2 and deg[u]%2!=1)return 0;
	for(int i=1;i<=n;i++){
		for(int k=0;k<g[i].size();k++){
			if(vis[i][g[i][k]])continue;
			link(i,g[i][k]);
		}
	}
	eular(u);
	for(int i=1;i<=n;i++){
		for(int k=0;k<g[i].size();k++){
			bj[i][g[i][k]]=0;
		}
	}
	return ((head-1+zs)>=m);
}
bool ans[N];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	bool flag=0;
	for(int i=1;i<=n;i++){
		zs=0;tem=i;
		for(int k=0;k<v[i].size();k++){
			if(in[v[i][k]]&1){
				zs++;
				ans[v[i][k]]=1;
			}
			else{
				g[v[i][k]].push_back(i);
				g[i].push_back(v[i][k]);
			}
			pd[i][v[i][k]]=1;
			pd[v[i][k]][i]=1;
		}
		for(int k=1;k<=top;k++){
			if(pd[stx[k]][sty[k]]){
				continue;
			}
			g[stx[k]].push_back(sty[k]);
		//	g[sty[k]].push_back(stx[k]);
		}
		if(check(i)){
			flag=1;
			break;
		}
		for(int k=0;k<v[i].size();k++){
			if(i==1 and k==1){
				new char;
			}
			if(in[v[i][k]]&1){
				zs--;
				ans[v[i][k]]=0;
				g[v[i][k]].push_back(i);
				g[i].push_back(v[i][k]);
				if(check(i)){
					flag=1;
					break;
				}
				ans[v[i][k]]=1;
				zs++;
				vis[i][v[i][k]]=vis[v[i][k]][i]=1;
			}
			else{
				vis[i][v[i][k]]=vis[v[i][k]][i]=1;
				zs++;
				ans[v[i][k]]=1;
				if(check(i)){
					flag=1;
					break;
				}
				ans[v[i][k]]=0;
				zs--;
				vis[i][v[i][k]]=vis[v[i][k]][i]=0;
			}
		}
		for(int k=0;k<v[i].size();k++){
			if(in[v[i][k]]&1){
				vis[i][v[i][k]]=vis[v[i][k]][i]=0;
			}
		}
		if(flag)break;
		for(int k=0;k<v[i].size();k++){
			pd[i][v[i][k]]=0;
			pd[v[i][k]][i]=0;
		}
		for(int k=1;k<=n;k++){
			ans[k]=0;
			vector<int>().swap(g[k]);
		}
	}
	if(!flag){
		cout<<0;
	}
	else{
		int buf=0;
		for(int k=1;k<=n;k++){
			if(ans[k])buf++;
		}
		printf("%d\n",head+buf*2+(buf?1:0));
		for(int i=1;i<=head;i++){
			printf("%d ",q[i]);
		}
		if(buf)printf("-1 ");
		for(int i=1;i<=n;i++){
			if(ans[i]){
				printf("%d %d ",i,tem);
			}
		}
	}
	return 0;
}