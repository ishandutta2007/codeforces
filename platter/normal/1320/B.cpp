#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200055];
vector<int> rev[200055];
int arr[200055];
int dist[200055];
int n,m;
const int INF=1e9;

void bfs(int v) {
	for(int i=0;i<n;i++) {
		dist[i]=INF;
	}
	queue<int> q;
	dist[v]=0;
	q.push(v);
	while (!q.empty()) {
		int curr=q.front();
		q.pop();
		for(int i=0;i<rev[curr].size();i++) {
			int next=rev[curr][i];
			if (dist[next]==INF) {
				dist[next]=dist[curr]+1;
				q.push(next);
			}
		}
	}
}

int main(void) {
	scanf("%d %d\n",&n,&m);
	for(int i=0;i<m;i++) {
		int u,v;
		scanf("%d %d\n",&u,&v);
		u--;
		v--;
		adj[u].push_back(v);
		rev[v].push_back(u);
	}
	int k;
	scanf("%d\n",&k);
	for(int i=0;i<k;i++) {
		scanf("%d ",&arr[i]);
		arr[i]--;
	}
	bfs(arr[k-1]);
	int mini=0;
	int maxi=0;
	for(int i=1;i<k;i++) { //arr[i-1]~arr[i]
		if (dist[arr[i-1]]!=dist[arr[i]]+1) {
			mini++;
			maxi++;
			continue;
		}
		for(int j=0;j<adj[arr[i-1]].size();j++) {
			if (adj[arr[i-1]][j]!=arr[i]) {
				int next=adj[arr[i-1]][j];
				if (dist[arr[i-1]]==dist[next]+1) {
					maxi++;
					break;
				}
			}
		}
	}
	printf("%d %d",mini,maxi);
}