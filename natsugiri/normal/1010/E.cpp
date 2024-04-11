#include<queue>
#include<tuple>
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

struct Close {
    int x, y, z;
    bool operator<(const Close &c) const {
	return z < c.z;
    }
};
Close C[100011];

const int INF = 1<<29;
struct Open {
//    int id;
    int x0, x1;
    int y0, y1;
    int z0, z1;

    void reset() {
	x0 = INF;
	x1 = -INF;
	y0 = INF;
	y1 = -INF;
	z0 = INF;
	z1 = -INF;
    }

    void expand(int x, int y, int z) {
	amin(x0, x);
	amax(x1, x);
	amin(y0, y);
	amax(y1, y);
	amin(z0, z);
	amax(z1, z);
    }

    bool contains(int x, int y, int z) const {
	return x0 <= x && x <= x1 &&
	    y0 <= y && y <= y1 &&
	    z0 <= z && z <= z1;
    }
};

// (z, op/cls, id);
typedef tuple<int, int, int> Tuple;

Open B;
Open R[100011];

int ans[100011];
bool out[100011];

int Xmax, Ymax, Zmax;
int N, M, K;

const int SIZE = 1<<17;
priority_queue<pair<int, int> > Q[SIZE*2];
void init() {
    REP (i, SIZE*2) while (!Q[i].empty()) Q[i].pop();
}

void insert(int id, int l=0, int r=SIZE, int k=1) {
    if (R[id].x1 < l || r <= R[id].x0) {
    } else if (R[id].x0 <= l && r-1 <= R[id].x1) {
	Q[k].emplace(R[id].y1, id);
    } else {
	int m = (l+r)/2;
	insert(id, l, m, k*2);
	insert(id, m, r, k*2+1);
    }
}

void query(const Close &c, int l=0, int r=SIZE, int k=1) {
    if (c.x < l || r <= c.x) {
    } else {
	while (!Q[k].empty()) {
	    int y = Q[k].top().first;
	    int id = Q[k].top().second;
	    if (out[id]) {
		Q[k].pop();
	    } else if (y >= c.y) {
		ans[id] = 2;
		Q[k].pop();
	    } else {
		break;
	    }
	}
	if (l + 1 == r) return;

	int m = (l+r)/2;
	query(c, l, m, k*2);
	query(c, m, r, k*2+1);
    }
}



void FILTER() {
    vector<Tuple> E;
    REP (i, K) if (ans[i] == 0) {
	E.emplace_back(R[i].z0, 0, i);
	E.emplace_back(R[i].z1, 1, i);
	out[i] = 0;
    }
    sort(E.begin(), E.end());
    sort(C, C+M);

    init();

    int cur = 0;
    REP (i, M) {
	while (cur < (int)E.size()) {
	    int z, tp, id;
	    tie(z, tp, id) = E[cur];

	    if (z < C[i].z && tp == 1) {
		// erase
		out[id] = true;
	    } else if (z <= C[i].z && tp == 0) {
		insert(id);
		// insert
	    } else {
		break;
	    }

	    cur++;
	}

	if (C[i].y >= B.y1) {
	    query(C[i]);
	}
    }
}

void MAIN() {
    scanf("%d%d%d%d%d%d", &Xmax, &Ymax, &Zmax, &N, &M, &K);
    B.reset();
    REP (i, N) {
	int x, y, z;
	scanf("%d%d%d", &x, &y, &z);
	B.expand(x, y, z);
    }

    bool correct = true;
    REP (i, M) {
	int x, y, z;
	scanf("%d%d%d", &x, &y, &z);
	C[i].x = x;
	C[i].y = y;
	C[i].z = z;

	if (B.contains(x, y, z)) {
	    correct = false;
	}
    }

    REP (i, K) {
	int x, y, z;
	scanf("%d%d%d", &x, &y, &z);
	R[i] = B;
//	R[i].id = i;
	if (B.contains(x, y, z)) {
	    ans[i] = 1; // OPEN
	} else {
	    R[i].expand(x, y, z);
	}
    }

    if (!correct) {
	puts("INCORRECT");
	return;
    }

    puts("CORRECT");


    REP (a, 3) {
	REP (c, 2) {
	    FILTER();
	    REP (i, K) {
		int tmp = R[i].y0;
		R[i].y0 = 100001 - R[i].y1;
		R[i].y1 = 100001 - tmp;
	    }
	    REP (i, M) {
		C[i].y = 100001 - C[i].y;
	    }
	    {
		int tmp = B.y0;
		B.y0 = 100001 - B.y1;
		B.y1 = 100001 - tmp;
	    }
	}

	REP (i, K) {
	    int tmp = R[i].x0;
	    R[i].x0 = R[i].y0;
	    R[i].y0 = R[i].z0;
	    R[i].z0 = tmp;
	    tmp = R[i].x1;
	    R[i].x1 = R[i].y1;
	    R[i].y1 = R[i].z1;
	    R[i].z1 = tmp;
	}
	REP (i, M) {
	    int tmp = C[i].x;
	    C[i].x = C[i].y;
	    C[i].y = C[i].z;
	    C[i].z = tmp;
	}
	{
	    int tmp = B.x0;
	    B.x0 = B.y0;
	    B.y0 = B.z0;
	    B.z0 = tmp;
	    tmp = B.x1;
	    B.x1 = B.y1;
	    B.y1 = B.z1;
	    B.z1 = tmp;
	}
    }

    REP (i, K) {
	if (ans[i] == 0) puts("UNKNOWN");
	else if (ans[i] == 1) puts("OPEN");
	else if (ans[i] == 2) puts("CLOSED");
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}