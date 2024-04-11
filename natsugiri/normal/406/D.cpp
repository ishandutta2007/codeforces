#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<deque>
#include<stack>
using namespace std;


typedef long long LL;

	
typedef vector<vector<int> > Mat;
const int MAX_V=1000000;
const int LOG_V=20;

struct LCA {
    vector<int> depth;
    vector<vector<int> > par; 
    LCA() {}
    LCA(Mat &T, int r=0) {
	int n = T.size();
	par = vector<vector<int> >(n, vector<int>(LOG_V));
	depth = vector<int>(n);
	stack<int>vv, pp;
	vv.push(r); pp.push(r);
	depth[r] = 0;
	for (;!vv.empty();) {
	    int v = vv.top(), p = pp.top();
	    vv.pop(); pp.pop();
	    par[v][0] = p;
	    for (int i=0; i<(int)T[v].size(); i++) {
		if (T[v][i] != p) {
		    vv.push(T[v][i]);
		    pp.push(v);
		    depth[T[v][i]] = depth[v]+1;
		}
	    }
	}
	for (int i=1; i<LOG_V; i++) {
	    for (int v=0; v<n; v++) par[v][i] = par[par[v][i-1]][i-1];
	}
    }
    int lca(int x, int y) {
	if (depth[x] < depth[y]) swap(x, y);
	for (int i=0; depth[x] != depth[y]; i++) {
	    if ((depth[x]-depth[y])&(1<<i)) x = par[x][i];
	}
	if (x == y) return x;
	for (int i=LOG_V; i--;) {
	    if (par[x][i] != par[y][i]) x=par[x][i], y=par[y][i];
	}
	return par[x][0];
    }
    int dist(int x, int y) {
	int z = lca(x, y);
	return depth[x] + depth[y] - 2 * depth[z];
    }
};


int N;
LL X[100010], Y[100010];
int parent[100010];
	   
int main() {
    ios_base::sync_with_stdio (false);
    cin >> N;
    for (int i=0; i<N; i++) cin >> X[i] >> Y[i];

    deque<int> v;
    parent[N-1] = -1;
    v.push_back(N-1);
    
    for (int i=N-2; i>=0; i--) {
	int l = 0, r = v.size();
	for (; r-l>1; ) {
	    int m = (l+r)/2;
	    LL x0 = X[v[m-1]], y0 = Y[v[m-1]];
	    LL x1 = X[v[m]], y1 = Y[v[m]];
	    // overflow?
	    if ((y1-Y[i]) * (x0 - X[i]) > (y0 - Y[i]) * (x1 - X[i])) l = m;
	    else r = m;
	}
	for (int j=0; j<l; j++) v.pop_front();
	parent[i] = v[0];
	v.push_front(i);
    }

//    for (int i=0; i<N; i++) printf("%d %d\n", i, parent[i]);

    Mat G(N);

    for (int i=0; i<N; i++) {
	if (parent[i] >= 0) {
	    G[i].push_back(parent[i]);
	    G[parent[i]].push_back(i);
	}
    }

    LCA lca(G, N-1);
    int Q;
    cin >> Q;

    for (;  Q--;) {
	int a, b;
	cin >> a >> b;
	a--; b--;;
	printf("%d%c", lca.lca(a, b)+1, Q ? ' ' : '\n');
    }
    

    return 0;
}