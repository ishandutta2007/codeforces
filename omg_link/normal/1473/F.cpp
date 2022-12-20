#include <stdio.h>
#include <string.h>
#include <queue>
#define MN (3000)
#define MM (MN*13*2)
#define MA (100)
const int INF = 0x3f3f3f3f;
const int S = MN+1;
const int T = MN+2;

int n,a[MN+5],b[MN+5],lst[MA+5];
int hd[MN+5],to[MM+5],nxt[MM+5],cap[MM+5];
int dep[MN+5],cur[MN+5];

void _add(int u,int v,int c){
	static int rn = 0;
	to[rn] = v;
	cap[rn] = c;
	nxt[rn] = hd[u];
	hd[u] = rn++;
}

void add(int u,int v,int c){
	_add(u,v,c);
	_add(v,u,0);
}

void bfs(){
	std::queue<int> q;
	memset(dep,0x3f,sizeof(dep));
	dep[S] = 0;
	q.push(S);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i=hd[u];~i;i=nxt[i]){
			if(!cap[i]) continue;
			if(dep[to[i]]!=INF) continue;
			dep[to[i]] = dep[u]+1;
			q.push(to[i]);
		}
	}
}

int flow(int u,int f){
	if(u==T) return f;
	int R = 0;
	for(int& i=cur[u];~i;i=nxt[i]){
		if(dep[to[i]]!=dep[u]+1) continue;
		if(cap[i]==0) continue;
		int c = std::min(f,cap[i]);
		int r = flow(to[i],c);
		cap[i] -= r;
		cap[i^1] += r;
		f -= r;
		R += r;
		if(f==0) break;
	}
	return R;
}

int dinic(){
	int ans = 0;
	for(bfs();dep[T]!=INF;bfs()){
		for(int i=1;i<=n;i++)
			cur[i] = hd[i];
		cur[S] = hd[S];
		ans += flow(S,INF);
	}
	return ans;
}

int main(){
	memset(hd,0xff,sizeof(hd));
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		for(int j=1;j*j<=a[i];j++){
			if(a[i]%j==0){
				if(lst[j])
					add(i,lst[j],INF);
				if(j*j!=a[i]&&lst[a[i]/j])
					add(i,lst[a[i]/j],INF);
			}
		}
		lst[a[i]] = i;
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		if(b[i]>0){
			add(S,i,b[i]);
			ans += b[i];
		}
		if(b[i]<0){
			add(i,T,-b[i]);
		}
	}
	printf("%d\n",ans-dinic());
}