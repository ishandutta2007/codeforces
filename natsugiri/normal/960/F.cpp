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

int N, M;
int from[100011], to[100011], weight[100011];

// (weight, len);
set<pair<int, int> > S[100011];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, M) {
	scanf("%d%d%d", from+i, to+i, weight+i);
	from[i]--;
	to[i]--;
    }

    int ans = 0;
    for (int i=M; i--;) {
	int x = from[i];
	int y = to[i];
	int w = weight[i];

	int len;
	{
	    auto it = S[y].lower_bound(make_pair(w+1, -1));
	    if (it != S[y].end()) {
		len = it->second + 1;
	    } else {
		len = 1;
	    }
	    amax(ans, len);
	}
	{
	    bool ins = true;
	    auto it = S[x].lower_bound(make_pair(w+1, -1));
	    if (it != S[x].end() && it->second >= len) ins = false;

	    if (ins) {
		while (it != S[x].begin()) {
		    --it;
		    if (it->first == w && it->second >= len) {
			ins = false;
			break;
		    }
		    if (it->second <= len) S[x].erase(it++);
		}
	    }
	    if (ins) {
		S[x].insert(make_pair(w, len));
	    }
	}

//	eprintf("%d : ", x+1);
//	EACH (e, S[x]) eprintf("%d %d, ", e->first, e->second);
//	eprintf("\n");
    }

    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}