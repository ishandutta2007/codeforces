#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

typedef long long LL;

struct Edge {
  int src, dst, cst;
};
bool operator<(Edge a, Edge b) {
  return a.cst>b.cst;
}

const int INF=0x3f3f3f3f;

vector<Edge>G[100010];
vector<int>travel[100010], next[100010], K;
int n, m;

int main(){
  scanf("%d%d", &n, &m);
  for (int i=0; i<m; i++) {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	a--; b--;
	G[a].push_back((Edge){a, b, c});
	G[b].push_back((Edge){b, a, c});
  }
  for (int i=0; i<n; i++) {
	int k;
	scanf("%d", &k);
	K.push_back(k);
	for (int j=0; j<k; j++) {
	  int x;
	  scanf("%d", &x);
	  travel[i].push_back(x);
	}
	next[i]=travel[i];
	if (k) next[i][k-1]=travel[i][k-1]+1;
	for (int j=k-2; j>=0; j--) {
	  if (travel[i][j]+1==travel[i][j+1]) next[i][j]=next[i][j+1];
	  else next[i][j]=travel[i][j]+1; 
	}
  }
  
  vector<int>len(n, INF), touch(n, INF);
  if (K[0] && travel[0][0]==0) len[0]=next[0][0];
  else len[0]=0;
  touch[0]=0;
  priority_queue<Edge>Q;
  Q.push((Edge){ -1, 0, len[0]});

  for (;!Q.empty();) {
	Edge e=Q.top(); Q.pop();
	if (e.cst==len[e.dst]) {
	  for (int i=0; i<int(G[e.dst].size()); i++) {
		Edge f=G[e.dst][i];
		int t=e.cst+f.cst;
		int x=lower_bound(travel[f.dst].begin(), travel[f.dst].end(), t)-travel[f.dst].begin();
		if (0<=x && x<K[f.dst] && travel[f.dst][x]==t) t=next[f.dst][x];
		if (len[f.dst]>t) {
		  touch[f.dst]=min(touch[f.dst], e.cst+f.cst);
		  len[f.dst]=t;
		  Q.push((Edge){ f.src, f.dst, t });
		}
	  }
	}
  }

  int ans=touch[n-1];
  if (ans==INF) ans=-1;
  printf("%d\n", ans);
  return 0;
}