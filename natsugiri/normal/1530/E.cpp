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
char S[100011];
int C[26];
string ans, X;

void II(const int i) {
    // ii ..;

    assert(C[i] >= 3);
    ans.push_back(i + 'a');
    ans.push_back(i + 'a');
    C[i] -= 2;

    X.clear();
    REP (k, 26) if (k != i) REP (t, C[k]) X.push_back(k + 'a');
    int xi = 0;

    REP (k, C[i]) {
	ans.push_back(X[xi++]);
	ans.push_back(i + 'a');
    }

    while (xi < (int)X.size()) ans.push_back(X[xi++]);

    assert((int)ans.size() == N);
    puts(ans.c_str());
}

void IJ(const int i) {
    // ij ..;

    assert(C[i] >= 3);

    ans.push_back(i + 'a');
    C[i]--;

    int j = i+1;
    while (C[j] == 0 && j < 26) j++;
    assert(j < 26);
    ans.push_back(j + 'a');
    C[j]--;

    if (C[i] + C[j] + 2 == N) {
	// eprintf("i j..j i..i\n");
	REP (t, C[j]) ans.push_back(j + 'a');
	REP (t, C[i]) ans.push_back(i + 'a');
    } else {
	// eprintf("i j i..i x j..j tail\n");
	int k = j+1;
	while (C[k] == 0 && k < 26) k++;
	assert(k < 26);

	REP (t, C[i]) ans.push_back(i + 'a');
	ans.push_back(k + 'a');
	C[k]--;
	for (int x=i+1; x<26; x++) REP (y, C[x]) ans.push_back(x + 'a');
    }
    assert((int)ans.size() == N);
    puts(ans.c_str());
}

void MAIN() {
    scanf("%s", S);
    N = strlen(S);

    memset(C, 0, sizeof C);
    REP (i, N) C[S[i]-'a']++;

    ans.clear();

    REP (t, 26) if (C[t] == 1) {
	ans.push_back(t + 'a');
	C[t]--;
	REP (i, 26) REP (j, C[i]) ans.push_back(i+'a');
	assert((int)ans.size() == N);
	puts(ans.c_str());
	return;
    }

    REP (t, 26) if (C[t]) {
	if (C[t] == N || C[t] <= 2) {
	    REP (i, 26) REP (j, C[i]) ans.push_back(i+'a');
	    assert((int)ans.size() == N);
	    puts(ans.c_str());
	    return;
	} else if (C[t]-2 <= N-C[t]) {
	    II(t);
	    return;
	} else {
	    IJ(t);
	    return;
	}
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}