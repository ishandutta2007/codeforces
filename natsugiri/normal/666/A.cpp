#include<unordered_set>
#include<map>
#include<bitset>
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

int N;
char S[10011];
set<string> ans;
bool dp[10011][2];



int main() {
    scanf("%s", S);
    N = strlen(S);

    dp[N][0] = dp[N][1] = true;
    for (int i=N; i>0; i--) {
	if (5 <= i-2) {
	    string key(S+i-2, S+i);
	    if (dp[i][1] || (dp[i][0] && key != string(S+i, S+i+2))) dp[i-2][0] = true;
	}
	if (5 <= i-3) {
	    string key(S+i-3, S+i);
	    if (dp[i][0] || (dp[i][1] && key != string(S+i, S+i+3))) dp[i-3][1] = true;
	}
    }


    REP (i, N) {
	if (dp[i][0]) ans.insert(string(S+i, S+i+2));
	if (dp[i][1]) ans.insert(string(S+i, S+i+3));
    }

    printf("%d\n", (int)ans.size());
    EACH (e, ans) puts(e->c_str());


    return 0;
}