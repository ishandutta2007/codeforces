#include <stdio.h>
#include <string.h>
#include <queue>
#define MN 200
#define MP MN*MN*2

const int INF=0x7f7f7f7f;

int n,m;
char c[MN+5][MN+5];

int snum=0,pnum=0;
bool ex[MP+5];
int hd[MP+5],to[MP*6+5],nxt[MP*6+5],val[MP*6+5];

int dep[MP+5];
bool vis[MP+5];

enum TYPE{RIGHT,DOWN};

int id(int x,int y,TYPE type){
	--x,--y;
	return (x*m+y)*2+(type==TYPE::RIGHT?1:2);
}

int getS(){return id(n+1,1,TYPE::RIGHT);}
int getT(){return id(n+1,1,TYPE::DOWN);}

void _add(int u,int v,int w){
	static int rn=0;
	to[rn]=v,val[rn]=w,nxt[rn]=hd[u];
	hd[u]=rn++;
}

void add(int u,int v){
	_add(u,v,1),_add(v,u,0);
}

void bfs(){
	memset(dep,0x7f,sizeof(dep));
	std::queue<int> q;
	dep[getS()] = 0;
	for(q.push(getS());!q.empty();){
		int u = q.front(); q.pop();
		for(int i=hd[u];~i;i=nxt[i]){
			if(!val[i]) continue;
			if(dep[to[i]]!=INF) continue;
			dep[to[i]] = dep[u]+1;
			q.push(to[i]);
		}
	}
}

bool flow(int u){
	if(vis[u]) return false;
	if(u==getT()) return true;
	for(int i=hd[u];~i;i=nxt[i]){
		if(dep[to[i]]!=dep[u]+1) continue;
		if(!val[i]) continue;
		val[i] = 0;
		val[i^1] = 1;
		if(flow(to[i])) return true;
		val[i] = 1;
		val[i^1] = 0;
	}
	vis[u] = true;
	return false;
}

int maxflow(){
	int ret=0;
	for(bfs();dep[getT()]!=INF;bfs()){
		memset(vis,false,sizeof(vis));
		while(flow(getS())) ret++;
	}
	return ret;
}

int main(){
	memset(hd,0xff,sizeof(hd));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",&c[i][1]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(c[i][j]=='#'){
				if(c[i+1][j]=='#'){
					ex[id(i,j,TYPE::DOWN)] = true;
					add(id(i,j,TYPE::DOWN),getT());
					pnum++;
				}
				if(c[i][j+1]=='#'){
					ex[id(i,j,TYPE::RIGHT)] = true;
					add(getS(),id(i,j,TYPE::RIGHT));
					pnum++;
				}
				snum++;
			}
		}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ex[id(i,j,TYPE::RIGHT)]){
				if(ex[id(i,j,TYPE::DOWN)]){
					add(id(i,j,TYPE::RIGHT),id(i,j,TYPE::DOWN));
				}
				if(ex[id(i,j+1,TYPE::DOWN)]){
					add(id(i,j,TYPE::RIGHT),id(i,j+1,TYPE::DOWN));
				}
				if(i>1&&ex[id(i-1,j,TYPE::DOWN)]){
					add(id(i,j,TYPE::RIGHT),id(i-1,j,TYPE::DOWN));
				}
				if(i>1&&ex[id(i-1,j+1,TYPE::DOWN)]){
					add(id(i,j,TYPE::RIGHT),id(i-1,j+1,TYPE::DOWN));
				}
			}
		}
	}
	printf("%d\n",snum-(pnum-maxflow()));
}