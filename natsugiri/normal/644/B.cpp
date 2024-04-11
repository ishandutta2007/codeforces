#include<queue>
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
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }

int N, B;
int T[200111], D[200111];
LL ans[200111];


int main() {
    scanf("%d%d", &N, &B);

    REP (i, N) scanf("%d%d", T+i, D+i);

    queue<int> qu;
    LL cur = -100;
    REP (i, N+1) {
	while (!qu.empty() && (cur <= T[i] || i == N)) {
	    int k = qu.front(); qu.pop();
	    ans[k] = cur = max(cur, (LL)T[k]) + D[k];
	}

	if ((int)qu.size() < B) {
	    qu.push(i);
	} else {
	    ans[i] = -1;
	}
    }

    REP (i, N) printf("%lld%c", ans[i], i==N-1? '\n': ' ');


    return 0;
}