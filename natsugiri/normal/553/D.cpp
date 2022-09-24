#include<stack>
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (b<a) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

typedef vector<VI> Adj;
Adj G;

const int MAX = 100111;
int N, M, K;
bool F[MAX];
bool use[MAX];
int deg[MAX];

bool solve(long double W) {
    REP (i, N) deg[i] = G[i].size();
    stack<int> bad;
    memset(use, 0, sizeof use);
    REP (i, N) if (F[i]) {
	bad.push(i);
	use[i] = true;;
    }

    while (!bad.empty()) {
	int v = bad.top(); bad.pop();
	EACH (e, G[v]) {
	    if (!use[*e]) {
		deg[*e]--;
		if (deg[*e] < W * G[*e].size()) {
		    use[*e] = true;
		    bad.push(*e);
		}
	    }
	}
    }

    REP (i, N) if (!use[i]) return true;
    return false;
}

int main() {
    scanf("%d%d%d", &N, &M, &K);
    REP (i, K) {
	int a;
	scanf("%d", &a);
	F[a-1] = true;
    }

    G.resize(N);
    
    REP (i, M) {
	int a, b;
	scanf("%d%d", &a, &b);
	a--; b--;
	G[a].push_back(b);
	G[b].push_back(a);
    }

    long double lo = -0.1, hi = 1.1;
    REP (i, 60) {
	double m = (lo + hi) / 2;
	if (solve(m)) lo = m;
	else hi = m;
    }
    eprintf("%Lf\n", lo);
    solve(lo);

    VI ans;
    REP (i, N) if (!use[i]) ans.push_back(i);
    printf("%d\n", (int)ans.size());
    REP (i, ans.size()) printf("%d%c", ans[i]+1, i+1 == (int)ans.size() ? '\n' : ' ');
    
    return 0;
}