#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

bool ok(char *S, char *T, int len) {
    REP (i, len) if (S[i] != T[i]) return false;
    return true;
}
char S[100111], T[100111];
int N;
int main() {
    scanf("%d%s%s", &N, S, T);

    int p = -1, q = -1;
    REP (i, N) {
	if (S[i] != T[i]) {
	    if (p == -1) p = i;
	    q = i;
	}
    }

    int cnt = 0;
    // [p .. q]
    if (ok(S+p+1, T+p, q-p)) cnt++;
    if (ok(T+p+1, S+p, q-p)) cnt++;
    printf("%d\n", cnt);
    return 0;
}