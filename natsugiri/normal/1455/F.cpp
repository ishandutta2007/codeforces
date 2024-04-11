#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

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

int N, K;
char S[511];
int A[511];

int up(int a) { return a == K-1? 0: a+1; }
int down(int a) { return a? a-1: K-1; }

string dp[511][26];

string con(string s, int a) {
    s.push_back(a + 'a');
    return s;
}

void update(string &s, const string &t) {
    if (s == "|") {
	s = t;
    } else {
	assert(s.size() == t.size());
	int R = s.size();
	int L = max(0, R - 5);
	for (int i=L; i<R; i++) {
	    if (s[i] < t[i]) break;
	    if (s[i] > t[i]) {
		while (i < R) {
		    s[i] = t[i];
		    i++;
		}
		break;
	    }
	}
    }
}

void MAIN() {
#ifdef LOCAL
    N = 500;
    K = 26;
    REP (i, N) {
	A[i] = rand() % K;
	S[i] = A[i] + 'a';
    }
#else
    scanf("%d%d", &N, &K);
    scanf("%s", S);
    REP (i, N) A[i] = S[i] - 'a';
#endif

    REP (i, N+1) REP (a, K) dp[i][a] = "|";
    dp[0][0] = "";

    REP (i, N) {
	string prefix = *min_element(dp[i], dp[i] + K);
	REP (a, K) if (dp[i][a] == prefix) {
	    int b = A[i];
	    int c = A[i+1];

	    string tmp;
	    if (i == 0) {
		tmp = "";
	    } else {
		tmp = con(dp[i][a], a);
	    }

	    // 0, U, D;
	    int b2 = min(b, min(up(b), down(b)));
	    update(dp[i+1][b2], tmp);

	    if (1 <= i && b <= a) {
		// L;
		update(dp[i+1][a], con(dp[i][a], b));
	    }

	    if (i + 1 < N) {
		int c2 = min(c, min(up(c), down(c)));
		// R0, RU, RD;
		// abc R acb
		update(dp[i+2][b], con(tmp, c2));
	    }

	    if (1 <= i && i+1 < N && c <= a) {
		// RL;
		// abc R acb L cab
		update(dp[i+2][b], con(con(dp[i][a], c), a));
	    }
	}
    }

    string ans = "|";
    REP (a, K) if (dp[N][a] != "|") update(ans, con(dp[N][a], a));
    puts(ans.c_str());
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}