#include<set>
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
struct UnionFind {
    vector<int>U;
    int n;
    UnionFind() {}
    UnionFind(int n) :n(n) { U=vector<int>(n, -1); }
    int root(int x) {
	if (U[x]<0) return x;
	return U[x]=root(U[x]);
    }
    int link(int x, int y) {
	int p, q;
	p=root(x); q=root(y);
	if (p==q) return p;
	if (U[q]<U[p]) swap(p, q);
	U[p]+=U[q];
	n--;
	return U[q]=p;
    }
    bool same(int x, int y) { return root(x)==root(y); }
    int size() { return n; }
    int count(int x) { return -U[root(x)]; }
};

const LL MOD = 1000000007;
LL A[100111];
int N, M;

inline pair<int, int> ord(int a, int b) {
    if (a > b) return make_pair(b, a);
    return make_pair(a, b);
}

set<pair<int, int> > L, H;
int Lb[100111], Hb[100111];

typedef vector<VI> Adj;
int col[100111];
Adj G;
bool dfs(int v) {
    int c = 3 - col[v];
    EACH (e, G[v]) {
	if (col[*e] == 0) {
	    col[*e] = c;
	    if (!dfs(*e)) return false;
	}
	if (col[*e] != c) return false;
    }
    return true;
}

// bool evil(int i) {
//     EACH (e, H) {
// 	if (e->first != i && e->second != i) return false;
//     }
//     EACH (e, L) {
// 	if (e->first == i || e->second == i) return false;
//     }
//     return true;
// }

int name[100111];

int main() {
    scanf("%d%d", &N, &M);
    UnionFind U(N);
//    bool zero = false;
    
    REP (i, M) {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);

	a--; b--;
	if (c == 0) {
	    H.insert(ord(a, b));
	    Hb[a]++; Hb[b]++;
	} else {
	    L.insert(ord(a, b));
	    U.link(a, b);
	    Lb[a]++; Lb[b]++;
	}
    }

    int cnt = 0;
    REP (i, N) if (U.root(i) == i) name[i] = cnt++;
    REP (i, N) name[i] = name[U.root(i)];

    G = Adj(cnt);
    EACH (e, H) {
	int a = name[e->first], b = name[e->second];
	G[a].push_back(b);
	G[b].push_back(a);
    }

    LL ans = -1;
    REP (i, cnt) {
	if (!col[i]) {
	    col[i] = 1;
	    bool a = dfs(i);
	    if (!a) {
		puts("0");
		return 0;
	    }

	    if (ans == -1) ans = 1;
	    else ans = (ans + ans) % MOD;
	}
    }


    printf("%d\n", (int)ans);
    
    // if (N == 4) {
    // 	if (H.size() == 0u) {
    // 	    ans++;
    // 	}

    // 	REP (i, N) { // evil
    // 	    if (evil(i)) ans++;
    // 	    // bool ok = true;
    // 	    // REP (a, N) REP (b, N) {
    // 	    // 	if (a == i || b == i) { // (a, b) : hate
    // 	    // 	    if (L.count(ord(a, b))) ok = false;
    // 	    // 	} else { // love
    // 	    // 	    if (H.count(ord(a, b))) ok = false;
    // 	    // 	}
    // 	    // }
    // 	    // if (ok) ans++;
    // 	}

    // 	// cycle
    // 	int A[3][5] = {
    // 	    { 0, 1, 2, 3, 0},
    // 	    { 0, 1, 3, 2, 0},
    // 	    { 0, 2, 1, 3, 0},
    // 	};
	
    // 	REP (i, 3) {
    // 	    bool ok = true;
    // 	    EACH (e, H) {
    // 		int c = 0;
    // 		REP (j, 4) if (*e == ord(A[i][j], A[i][j+1])) c++;
    // 		if (c == 0) ok = false;
    // 	    }
    // 	    EACH (e, L) {
    // 		int c = 0;
    // 		REP (j, 4) if (*e == ord(A[i][j], A[i][j+1])) c++;
    // 		if (c > 0) ok = false;
    // 	    }
    // 	    if (ok) ans++;
    // 	}
	
    // } else {
    // 	if (H.size() == 0u) {
    // 	    ans = 1; // lovely
    // 	    REP (i, N) if (!Lb[i]) ans++;

    // 	} else {
    // 	    int one = 0, more = 0;
    // 	    REP (i, N) if (!Lb[i]) {
    // 		if (Hb[i] == 1) one++;
    // 		if (Hb[i] > 1) more++;
    // 	    }

    // 	    if (more == 1) {
    // 		REP (i, N) if (!Lb[i] && Hb[i] > 1 && evil(i)) ans++;
    // 	    } else if (more == 0) {
    // 		REP (i, N) if (!Lb[i] && Hb[i] == 1 && evil(i)) ans++;
    // 	    }
    // 	}
    // }


    // printf("%lld\n", ans);

    
    return 0;
}