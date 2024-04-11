#include<assert.h>
#include<set>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int N, M, Q;
int Deg[50011];
set<int> S[50011];
int Ea[150011], Eb[150011];

char op[250011];
int U[250011], V[250011];

pair<int, int> P[50011];
int Rank[50011];

bool online[50011];
int online_friend[50011];

int main() {
    scanf("%d%d%d", &N, &M, &Q);
    int O;
    scanf("%d", &O);
    REP (i, O) {
	int x;
	scanf("%d", &x);
	x--;
	online[x] = true;
    }
    REP (j, M) {
	scanf("%d%d", Ea+j, Eb+j);
	Ea[j]--; Eb[j]--;
	Deg[Ea[j]]++;
	Deg[Eb[j]]++;
    }
    REP (i, Q) {
	scanf("%s", op+i);
	if (op[i] == 'O' || op[i] == 'F' || op[i] == 'C') {
	    scanf("%d", U+i); U[i]--;
	} else {
	    scanf("%d%d", U+i, V+i);
	    U[i]--; V[i]--;
	}
    }

    REP (i, N) {
	P[i] = make_pair(Deg[i], i);
    }

    sort(P, P+N);
    
    REP (i, N) Rank[P[i].second] = i;

    REP (j, M) {
	int u = Ea[j], v = Eb[j];
	if (Rank[u] < Rank[v]) swap(u, v);
	S[v].insert(u);
    }

    REP (i, N) if (online[i]) {
	EACH (e, S[i]) online_friend[*e]++;
    }

    REP ($, Q) {
	int u = U[$], v = V[$];
	if (op[$] == 'O') {
	    EACH (e, S[u]) online_friend[*e]++;
	    online[u] = true;
	} else if (op[$] == 'F') {
	    EACH (e, S[u]) online_friend[*e]--;
	    online[u] = false;
	} else if (op[$] == 'A') {
	    if (Rank[u] < Rank[v]) swap(u, v);
	    S[v].insert(u);
	    if (online[v]) online_friend[u]++;

	    int x = P[Rank[v]+1].second;
	    if (S[x].size() + 1u < S[v].size()) {
		swap(P[Rank[v]], P[Rank[x]]);
		Rank[v]++; Rank[x]--;
		if (S[v].find(x) != S[v].end()) {
		    S[v].erase(x);
		    S[x].insert(v);
		    if (online[v]) online_friend[x]--;
		    if (online[x]) online_friend[v]++;
		}
	    }

	} else if (op[$] == 'D') {
	    if (Rank[u] < Rank[v]) swap(u, v);
	    S[v].erase(u);
	    if (online[v]) online_friend[u]--;

	    if (Rank[v]) {
		int x = P[Rank[v]-1].second;
		if (S[v].size() + 1u < S[x].size()) {
		    swap(P[Rank[v]], P[Rank[x]]);
		    Rank[v]--; Rank[x]++;
		    if (S[x].find(v) != S[x].end()) {
			S[x].erase(v);
			S[v].insert(x);
			if (online[x]) online_friend[v]--;
			if (online[v]) online_friend[x]++;
		    }
		}
	    }
	} else if (op[$] == 'C') {
	    int ans = online_friend[u];
	    EACH (e, S[u]) if (online[*e]) ans++;
	    printf("%d\n", ans);
	} else {
	    assert(false);
	}
    }

    return 0;
}