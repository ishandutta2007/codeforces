#include <stdio.h>
#include <vector>
#include <algorithm>

#define N 1010

#define A first
#define B second

using namespace std;

typedef pair<int,int> pii;

vector<int> adj[N];

int out[N];
int Size[N];
pii arr[N];

int n,m;

int main() {
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++) {
		scanf("%d",&arr[i].A);
		arr[i].B = i;
		Size[i] = arr[i].A;
		out[i] = 0;
	}
	sort(arr + 1, arr+n+1);
	
	for(int i = 0;i < m;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int ans = 0;
	for(int i=n;i > 0;i--) {
		int u = arr[i].B;
		for(int j=0;j < adj[u].size();j++) {
			int v = adj[u][j];
			if(!out[v]) {
				ans += Size[v];
			}
		}
		out[u] = 1;
	}
	printf("%d\n",ans);
	return 0;
}