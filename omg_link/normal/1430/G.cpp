#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>
#define MN 18

int n,m;
int din[MN],a[MN],v[MN];
int f[1<<MN];

bool ex[MN][1<<MN];

std::vector<int> e[MN];
std::vector<int> topo;

struct dpFromData{
	dpFromData* from;
	int currentPoint;
	int currentValue;
	dpFromData(){
		throw "Wrong Calling";
	}
	dpFromData(dpFromData* ptr,int cp,int cv){
		from = ptr;
		currentPoint = cp;
		currentValue = cv;
	}
}*fr[1<<MN];

void add(int u,int v,int w){
	e[u].push_back(v);
	a[u] += w;
	a[v] -= w;
	din[v]++;
}

void getTopo(){
	std::queue<int> q;
	topo.clear();
	for(int i=0;i<n;i++)
		if(din[i]==0) q.push(i);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		topo.push_back(u);
		for(auto to:e[u])
			if(--din[to]==0)
				q.push(to);
	}
}

void getEx(){
	for(int i=0;i<n;i++){
		int mask = 0;
		for(auto to:e[i])
			mask |= (1<<to);
		for(int S=0;S<(1<<n);S++){
			ex[i][S] = ((S&mask)==mask);
		}
	}
}

void showAnswer(){
	for(dpFromData* ptr=fr[(1<<n)-1];ptr!=nullptr;ptr=ptr->from){
		v[ptr->currentPoint] = ptr->currentValue;
	}
	for(int i=0;i<n;i++)
		printf("%d ",v[i]);
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		--u,--v;
		add(u,v,w);
	}
	getTopo();
	getEx();
	memset(f,0x3f,sizeof(f));
	f[0] = 0;
	fr[0] = nullptr;
	for(int v=0;v<n;v++){
		for(int i=0;i<n;i++){
			int u = topo[i];
			for(int S=0;S<(1<<n);S++){
				if(!(S&(1<<u))) continue;
				int T = S^(1<<u);
				if(!ex[u][T]) continue;
				if(f[T]+a[u]*v<f[S]){
					f[S] = f[T]+a[u]*v;
					fr[S] = new dpFromData(fr[T],u,v);
				}
			}
		}
	}
	showAnswer();
}