#include<queue>
#include<cstdio>
using namespace std;
const int maxn=100000;
int n,m,s;
vector<int> g[maxn+10];
vector<int> z[maxn+10];
int pre[maxn+10][2],cnt,dz[maxn+10];
queue<pair<int,int> > q;
queue<int> qq;
void trace(int x,int y){
	if(pre[x][y]!=-1) trace(pre[x][y],y^1);
	printf("%d ",x);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		int k; scanf("%d",&k);
		for(;k--;){
			int x; scanf("%d",&x);
			g[i].push_back(x);
		}
	}
	scanf("%d",&s); pre[s][0]=-1; q.push(make_pair(s,0));
	for(;!q.empty();q.pop()){
		pair<int,int> x=q.front();
		for(int i=0;i<g[x.first].size();++i){
			pair<int,int> e=make_pair(g[x.first][i],x.second^1);
			if(!pre[e.first][e.second]){
				pre[e.first][e.second]=x.first; q.push(e);
			}
		}
	}
	for(int i=1;i<=n;++i) if(!g[i].size()&&pre[i][1]){
		printf("Win\n"); trace(i,1); return 0;
	}
	for(int i=1;i<=n;++i) if(pre[i][0]||pre[i][1]){
		++cnt;
		for(int j=0;j<g[i].size();++j){
			int e=g[i][j]; if(pre[e][0]||pre[e][1]){
				z[i].push_back(e); ++dz[e];
			}
		}
	}
	for(int i=1;i<=n;++i) if(pre[i][0]||pre[i][1])
		if(!dz[i]) qq.push(i);
	for(;!qq.empty();qq.pop()){
		int x=qq.front(); --cnt;
		for(int i=0;i<z[x].size();++i){
			int e=z[x][i]; if(!--dz[e]) qq.push(e);
		}	
	}
	printf("%s",cnt?"Draw":"Lose");
}