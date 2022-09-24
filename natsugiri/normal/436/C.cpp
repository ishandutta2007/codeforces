#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cstring>
#include<stack>
using namespace std;

typedef long long LL;
const int INF = 1<<29;

struct Edge {
    int src, dst, cst;
};
bool operator<(const Edge &x, const Edge &y) {
    return x.cst > y.cst;
}
typedef vector<vector<Edge> > Graph;

vector<int>len, prev;
void mst(Graph &G, int s) {
    int N = G.size();
    len.assign(N, INF);
    len[s] = 0;
    prev.assign(N, -2);
    priority_queue<Edge>Q;
    Q.push((Edge){-1, s, 0});

    while (!Q.empty()) {
	Edge e = Q.top(); Q.pop();

	if (prev[e.dst] == -2) {
	    prev[e.dst] = e.src;
	    len[e.dst] = e.cst;
	} else continue;

	for (int i=0; i<(int)G[e.dst].size(); i++) {
	    Edge f = G[e.dst][i];
	    if (prev[f.dst] == -2) {
		Q.push(f);
	    }
	}
    }
}

int N, M, K, W;
vector<string> F[1111];

int diff(int x, int y) {
    int ans = 0;
    for (int i=0; i<N; i++) {
	for (int j=0; j<M; j++) {
	    if (F[x][i][j] != F[y][i][j]) ans += W;
	}
    }
    return ans;
}

void output(Graph &G) {
    int sum = 0;
    for (int i=0; i<K; i++) sum += len[i];
    printf("%d\n", sum);
    stack<int> st;
    vector<int> use(K+1);
    st.push(K);
    use[K] = 1;
    while (!st.empty()) {
	int x = st.top(); st.pop();
	for (int i=0; i<(int)G[x].size(); i++) {
	    int y = G[x][i].dst;
	    if (prev[y] == x && !use[y]) {
		printf("%d %d\n", y+1, x==K ? 0 : x+1);
		use[y] = 1;
		st.push(y);
	    }
	}
    }
}

int main() {
    scanf("%d%d%d%d", &N, &M, &K, &W);
    
    Graph G(K+1);
    for (int i=0; i<K; i++) {
	string s;
	for (int y=0; y<N; y++) {
	    cin >> s;
	    F[i].push_back(s);
	}
    }

    for (int i=0; i<K; i++) {
	G[K].push_back((Edge){K, i, N*M});
	for (int j=0; j<i; j++) {
	    int c = diff(i, j);
	    G[i].push_back((Edge){i, j, c});
	    G[j].push_back((Edge){j, i, c});
	}
    }

    mst(G, K);
//    for (int i=0; i<=K; i++) cerr << len[i] << ' '; cerr << endl;
    output(G);
	    
    return 0;
}