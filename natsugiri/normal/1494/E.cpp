#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<set>
#include<map>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

int N;
int M;
char op[11];

map<pair<int, int>, char> mp;

int ODD;
int EVEN;


void MAIN() {
    scanf("%d%d", &N, &M);
    REP ($, M) {
	scanf("%s", op);
	
	if (*op == '+') {
	    int x, y;
	    scanf("%d%d%s", &x, &y, op);
	    x--; y--;
	    char c = *op;

	    auto it = mp.find(make_pair(y, x));
	    if (it != mp.end()) {
		ODD++;
		if (it->second == c) {
		    EVEN++;
		}
	    }
	    mp[make_pair(x, y)] = c;

	} else if (*op == '-') {
	    int x, y;
	    scanf("%d%d", &x, &y);
	    x--; y--;

	    auto it = mp.find(make_pair(x, y));
	    char c = it->second;
	    mp.erase(it);
	    it = mp.find(make_pair(y, x));

	    if (it != mp.end()) {
		if (it->second == c) {
		    EVEN--;
		}
		ODD--;
	    }
	} else {
	    int k;
	    scanf("%d", &k);
	    bool yes ;

	    if (k % 2 == 0) {
		yes = (EVEN >= 1);
	    } else {
		yes = (ODD >= 1 || ODD >= 1);
	    }
	    puts(yes? "YES": "NO");
	}
    }

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}