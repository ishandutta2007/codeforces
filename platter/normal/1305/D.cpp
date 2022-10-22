#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
int deg[1001];
bool used[1001];

int main(void) {
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++) {
		int u,v;
		scanf("%d %d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}
	for(int i=1;i<n;i+=2) {
		vector<int> v;
		for(int j=1;j<=n;j++) {
			if (deg[j]==1&&(!used[j])) {
				v.push_back(j);
			}
			if (v.size()==2) {
				break;
			}
		}
		used[v[0]]=true;
		used[v[1]]=true;
		for(int j=0;j<adj[v[0]].size();j++) {
			deg[adj[v[0]][j]]--;
		}
		for(int j=0;j<adj[v[1]].size();j++) {
			deg[adj[v[1]][j]]--;
		}
		printf("? %d %d\n",v[0],v[1]);
		fflush(stdout);
		int x;
		scanf("%d",&x);
		if (x==v[0]||x==v[1]) {
			printf("! %d\n",x);
			fflush(stdout);
			return 0;
		}
	}
	for(int i=1;i<=n;i++) {
		if (!used[i]) {
			printf("! %d\n",i);
			fflush(stdout);
			return 0;
		}
	}
}