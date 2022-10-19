#include<bits/stdc++.h>

using namespace std;

#define N 320000

int n,m,f[N],ans;
struct graph{
	vector<int> g[N];
	int cnt,d[N];
	queue<int> q;
	void add(int x,int y){
		g[x].push_back(y);
		++d[y];
	}
	void dec(int x){
		--d[x];
		if (!d[x]){q.push(x); --cnt;}
	}
	void solve(){
		cnt=n;
		for (int i=1;i<=n;++i){
			if (!d[i]){
				q.push(i);
				--cnt;
			}
		}
		while (!q.empty()){
			int u=q.front(); q.pop();
			if (q.size()==0) f[u]+=cnt;
			if (q.size()==1){
				int w=q.front(),tmp=0;
				for (int v:g[w]){
					if (d[v]==1) tmp=n;
				}
				f[u]+=cnt-tmp;
			}
			for (int v:g[u]) dec(v);
		}
	}
}g1,g2;

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i){
		int x,y; scanf("%d%d",&x,&y);
		g1.add(x,y);
		g2.add(y,x);
	}
	g1.solve(); g2.solve();
	for (int i=1;i<=n;++i){
		if (f[i]>=n-2) ++ans;
	}
	printf("%d\n",ans);
	
	return 0;
}