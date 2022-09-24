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

template<class T> inline void amin(T &a, const T &b) { if (b<a) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

int N, M, A[200011];
int L, R, X;
int nxt[200011];

int main() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%d", A+i);
    memset(nxt, -1, sizeof nxt);
    for (int i=N-2; i>=0; i--) {
	if (A[i] != A[i+1]) nxt[i] = i+1;
	else nxt[i] = nxt[i+1];
    }
    REP ($, M) {
	scanf("%d%d%d", &L, &R, &X);
	L--;
	int ans;
	if (A[L] != X) ans = L;
	else ans = nxt[L];
	
	if (ans >= R) ans = -1;

	if (ans == -1) puts("-1");
	else printf("%d\n", ans+1);
    }
	
    return 0;
}