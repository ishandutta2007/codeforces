#include <bits/stdc++.h>
using namespace std;

int sub[200000];
int pdp[200000];
int p[200000];
vector<int> adj[200000];
int n;
int arr[200000];
bool visited[200000];
vector<int> son[200000];
int nn=-1e7;

void maketree(int v) {
	visited[v]=true;
	for(int i=0;i<adj[v].size();i++) {
		int next=adj[v][i];
		if (!visited[next]) {
			son[v].push_back(next);
			p[next]=v;
			maketree(next);
		}
	}
}

int subans(int v) {
	if (sub[v]!=nn) {
		return sub[v];
	}
	int ret=arr[v];
	for(int i=0;i<son[v].size();i++) {
		if (subans(son[v][i])>0) {
			ret+=subans(son[v][i]);
		}
	}
	sub[v]=ret;
	return ret;
}

int ans(int v) {
	if (pdp[v]!=nn) {
		return pdp[v];
	}
	int ret=subans(v);
	if (v==0) {
		pdp[v]=ret;
		return ret;
	}
	ret=max(ret,ans(p[v])+min(0,ret));
	pdp[v]=ret;
	return ret;
}

int main(void) {
	scanf("%d\n",&n);
	for(int i=0;i<n;i++) {
		int x;
		scanf("%d ",&x);
		arr[i]=(x?1:-1);
	}
	for(int i=1;i<n;i++) {
		int u,v;
		scanf("%d %d\n",&u,&v);
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	maketree(0);
	for(int i=0;i<n;i++) {
		sub[i]=nn;
		pdp[i]=nn;
	}
	for(int i=0;i<n;i++) {
		printf("%d ",ans(i));
	}
}