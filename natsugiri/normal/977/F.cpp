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

int N;
int A[200011];
int nxt[200011];
int len[200011];
map<int, int> mp;

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    for (int i=N; i--;) {
	len[i] = 1;
	nxt[i] = N;
	auto it = mp.find(A[i]+1);
	if (it != mp.end()) {
	    len[i] = len[it->second] + 1;
	    nxt[i] = it->second;
	}
	mp[A[i]] = i;
    }

    int k = max_element(len, len+N) - len;
    VI ans;
    while (1) {
	ans.push_back(k+1);
	k = nxt[k];
	if (k == N) break;
    }

    printf("%d\n", (int)ans.size());
    rprintf("%d", ans.begin(), ans.end());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}