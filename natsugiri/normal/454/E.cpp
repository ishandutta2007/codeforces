#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0; i<int(n); i++)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)

typedef vector<vector<int> > Adj;

int N, M, X[100011];
bool use[100011];
Adj G;

vector<int> ans;
void vis(int v) {
    ans.push_back(v);
    X[v] = 1-X[v];
}

void dfs(int v, int p) {
    use[v] = true;
    vis(v);
    REP (i, G[v].size()) {
	int w = G[v][i];
	if (use[w]) continue;
	dfs(w, v);
	vis(v);
    }
    if (X[v]) {
	if (p == -1) {
	    ans.pop_back();
	    X[v] = 1 - X[v];
	} else {
	    vis(p); vis(v);
	}
    }
}

int main() {
    scanf("%d%d", &N, &M);
    G = Adj(N);
    REP (i, M) {
	int v, w;
	scanf("%d%d", &v, &w);
	v--; w--;
	G[v].push_back(w);
	G[w].push_back(v);
    }
    REP (i, N) scanf("%d", X+i);

    REP (i, N) if (X[i]) {
	dfs(i, -1);
	break;
    }

    if (X[0]) {
	ans.pop_back();
	X[0] = 1 - X[0];
    }

    bool ok = true;
    REP (i, N) if (X[i]) ok = false;
    
    if (!ok) {
	puts("-1");
    } else {
	printf("%d\n", (int)ans.size());
	REP (i, ans.size()) {
	    printf("%d%c", ans[i]+1, i+1 == (int)ans.size() ? '\n': ' ');
	}
    }


    return 0;
}