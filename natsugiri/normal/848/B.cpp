#include<map>
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

const LL MAX = 10000000;
int W, H;
int N;

struct Data {
    int x, y;
    LL key;
    int id;
    Data(){}
    Data(int x_, int y_, int i) {
	x = x_;
	y = y_;
	id = i;
	key = (LL)(MAX - y) << 32;
	key += x;
    }

    bool operator<(const Data&d) const {
	return key < d.key;
    }
};

const int BASE = 100111;
vector<Data> mp[BASE * 2];

int ansX[100111];
int ansY[100111];

void MAIN() {
    scanf("%d%d%d", &N, &W, &H);
    REP (i, N) {
	int g, p, t;
	scanf("%d%d%d", &g, &p, &t);

	if (g == 1) {
	    mp[t-p + BASE].push_back(Data(p, 0, i));
	} else {
	    mp[t-p + BASE].push_back(Data(0, p, i));
	}
    }

    REP (I_, BASE * 2) {
	if (mp[I_].empty()) continue;
	vector<Data> &v = mp[I_];
	vector<Data> w; w.reserve(v.size());
	REP (i, v.size()) {
	    if (v[i].x == 0) {
		w.push_back(Data(W, v[i].y, -1));
	    } else {
		w.push_back(Data(v[i].x, H, -1));
	    }
	}

	sort(v.begin(), v.end());
	sort(w.begin(), w.end());
	REP (i, v.size()) {
	    ansX[v[i].id] = w[i].x;
	    ansY[v[i].id] = w[i].y;
	}
    }

    REP (i, N) printf("%d %d\n", ansX[i], ansY[i]);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}