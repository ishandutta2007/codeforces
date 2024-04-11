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

int N, Q;
bool Z[300111];
VI A[300111];
int B[300111];
int ans;


int main() {
    scanf("%d%d", &N, &Q);

    REP (i, Q) {
	int op, x;
	scanf("%d%d", &op, &x);
	if (op == 1) {
	    x--;
	    A[x].push_back(i);
	    A[N].push_back(i);
	    ans++;
	} else if (op == 2) {
	    x--;
	    while (B[x] < (int)A[x].size()) {
		if (not Z[A[x][B[x]]]) ans--;
		Z[A[x][B[x]++]] = true;
	    }
	} else {
	    while (B[N] < x) {
		if (not Z[A[N][B[N]]]) ans--;
		Z[A[N][B[N]++]] = true;
	    }
	}

	printf("%d\n", ans);
    }


    return 0;
}