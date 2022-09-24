#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
using namespace std;

typedef long long LL;
typedef vector<vector<int> > Mat;

int N;
const int INF=1<<29;
const int MAX_N = 100010;
bool centroid[MAX_N];
int sz[MAX_N], subtree_sz[MAX_N];
int rank[MAX_N];

// subtree of k
int subtree_size(const Mat&G, int k, int p) {
    int c=1;
    for (int i=0; i<int(G[k].size()); i++) {
	int s=G[k][i];
	if (s==p || centroid[s]) continue;
	c += subtree_size(G, s, k);
    }
    return subtree_sz[k]=c;
}
// (max subtree_size, node to delete)
pair<int,int>search_centroid(const Mat&G, int k, int p, int t) {
    pair<int,int> ret(INF, -1);
    int s=1, m=0;
    for (int i=0; i<int(G[k].size()); i++) {
	int w=G[k][i];
	if (w==p || centroid[w]) continue;
	ret = min(ret, search_centroid(G, w, k, t));
	m = max(m, subtree_sz[w]);
	s += subtree_sz[w];
    }
    m = max(m, t-s);
    return min(ret, make_pair(m, k));
}
void dfs(const Mat&G, int k, int p, int cnt) {
    subtree_size(G, k, p);
    int t=search_centroid(G, k, p, subtree_sz[k]).second;
    centroid[t] = true;
    rank[t] = cnt;
    for (int i=0; i<int(G[t].size()); i++) {
	if (G[t][i]==p || centroid[G[t][i]]) continue;
	dfs(G, G[t][i], t, cnt+1);
    }
}
int main() {
    scanf("%d", &N);

    Mat G(N);

    for (int i=1; i<N; i++) {
	int a, b; scanf("%d%d", &a, &b); a--; b--;
	G[a].push_back(b);
	G[b].push_back(a);
    }

    dfs(G, 0, -1, 0);
    
    for (int i=0; i<N; i++)     
	printf("%c%c", rank[i]+'A', i+1==N?'\n':' ');

    return 0;

}