#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<set>

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
char buf[111];
string S[100011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	scanf("%s", buf);
	S[i] = buf;
    }

    bool yes = false;
    REP (i, N) {
	if (S[i][0] == S[i].back()) yes = true;
    }

    if (!yes) {
	// ab ba
	// ab cba
	// abc ba
	//
	// abc cba

	set<string> se2, se23, se3;
	string key2(2, '?');
	string key3(3, '?');
	REP (i, N) {
	    if (S[i].size() == 2u) {
		key2 = S[i];
		reverse(key2.begin(), key2.end());
		if (se2.find(key2) != se2.end()) {
		    yes = true;
		    break;
		}
		if (se23.find(key2) != se23.end()) {
		    yes = true;
		    break;
		}
		se2.insert(S[i]);
	    } else {
		key2[0] = S[i][2];
		key2[1] = S[i][1];
		if (se2.find(key2) != se2.end()) {
		    yes = true;
		    break;
		}

		key2[0] = S[i][0];
		key2[1] = S[i][1];
		se23.insert(key2);

		key3 = S[i];
		reverse(key3.begin(), key3.end());
		if (se3.find(key3) != se3.end()) {
		    yes = true;
		    break;
		}
		se3.insert(S[i]);
	    }
	}
    }

    puts(yes? "YES": "NO");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}