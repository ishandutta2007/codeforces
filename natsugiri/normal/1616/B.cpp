#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
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

int N;
char buf[100011];

void MAIN() {
    scanf("%d%s", &N, buf);

    string S = buf;
    string R = S;
    reverse(R.begin(), R.end());

    string ans = S + R;

    for (int i=1; i<(int)S.size(); i++) {
	if (S[i-1] < S[i]) {
	    string g = S.substr(0, i) + R.substr(N-i);
	    amin(ans, g);
	    break;
	} else if (S[i-1] == S[i]) {
	    if (i == 1 || i == (int)S.size()-1 || S[i-2] != S[i-1] || S[i] != S[i+1]) {
		string g = S.substr(0, i) + R.substr(N-i);
		amin(ans, g);
	    }
	}
    }

    puts(ans.c_str());
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}