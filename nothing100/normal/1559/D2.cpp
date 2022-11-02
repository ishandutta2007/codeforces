#include<bits/stdc++.h>
using namespace std;
int n,m1,m2,f[2][100010];
vector<int> edge[2][100010];
queue<int> q;
int get(int x,int y){
	if (f[x][y]==y) return y;
	f[x][y]=get(x,f[x][y]);
	return f[x][y];
}
void merge(int wh,int x,int y){
	x=get(wh,x);
	y=get(wh,y);
	if (x!=y) f[wh][x]=y;
}
void dfs(int wh,int x,int y){
	q.push(x);
	for (int i=0;i<edge[wh][x].size();i++)
	if (edge[wh][x][i]!=y) dfs(wh,edge[wh][x][i],x);
}
int main(){
	scanf("%d%d%d",&n,&m1,&m2);
	int o,p;
	for (int i=1;i<=n;i++) f[0][i]=f[1][i]=i;
	for (int i=0;i<m1;i++){
		scanf("%d%d",&o,&p);
		edge[0][o].push_back(p);
		edge[0][p].push_back(o); 
		merge(0,o,p);
	}
	//printf("gg\n");
	for (int i=0;i<m2;i++){
		scanf("%d%d",&o,&p);
		edge[1][o].push_back(p);
		edge[1][p].push_back(o);
		merge(1,o,p);
	}
	printf("%d\n",n-1-max(m1,m2));
	dfs(0,1,0);
	for (int i=2;i<=n;i++){
		o=get(0,i);
		p=get(0,1);
		int tmp1,tmp2;
		if (o!=p){
			tmp1=get(1,1);
			if (get(1,i)==tmp1){
				while (!q.empty()){
					tmp2=q.front();
					q.pop();
					if (get(1,tmp2)!=tmp1){
						printf("%d %d\n",tmp2,i);
						dfs(0,i,0);
						merge(0,i,tmp2);
						merge(1,i,tmp2);
						break;
					}
				}
			}
			else{
				printf("%d %d\n",1,i);
				dfs(0,i,0);
				merge(0,1,i);
				merge(1,1,i);
			}
		}
	}
}