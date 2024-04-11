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

int N;
char S[100111];

int cur[2][3], nxt[2][3];

int main() {
    scanf("%d%s", &N, S);

    
    for (int i=0; S[i]; i++) {
	REP (a, 2) REP (b, 3) nxt[a][b] = cur[a][b];
	
	if (S[i] == '0') {
	    amax(nxt[1][1], cur[0][0] + 1);
	    amax(nxt[1][1], cur[0][1] + 1);
	    amax(nxt[0][0], cur[1][0] + 1);
	    amax(nxt[0][2], cur[1][1] + 1);
	    amax(nxt[0][2], cur[1][2] + 1);
	} else {
	    amax(nxt[0][1], cur[1][0] + 1);
	    amax(nxt[0][1], cur[1][1] + 1);
	    amax(nxt[1][0], cur[0][0] + 1);
	    amax(nxt[1][2], cur[0][1] + 1);
	    amax(nxt[1][2], cur[0][2] + 1);
	}

	swap(cur, nxt);
    }

    int ans = 0;
    REP (a, 2) REP (b, 3) amax(ans, cur[a][b]);
    printf("%d\n", ans);
    return 0;
}