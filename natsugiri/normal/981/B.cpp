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

int N, M;

struct Data {
    int id;
    int x, y;
    Data() {
	id = -1;
	x = 0;
	y = 0;
    }
    bool operator<(const Data &t) const {
	return id != t.id ? id < t.id :
	    x < t.x;
    }
};

vector<Data> Z;

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	int a, x;
	scanf("%d%d", &a, &x);
	Data d;
	d.id = a;
	d.x = x;
	Z.push_back(d);
    }
    
    scanf("%d", &M);
    REP (i, M) {
	int b, y;
	scanf("%d%d", &b, &y);
	Data d;
	d.id = b;
	d.y = y;
	Z.push_back(d);
    }

    sort(Z.begin(), Z.end());

    REP (i, (int)Z.size()-1) {
	if (Z[i].id == Z[i+1].id) {
	    Z[i].x = max(Z[i].x, Z[i+1].x);
	    Z[i].y = max(Z[i].y, Z[i+1].y);
	    Z[i+1].x = 0;
	    Z[i+1].y = 0;
	}
    }

    LL ans = 0;
    EACH (e, Z) {
	ans += max(e->x, e->y);
    }
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}