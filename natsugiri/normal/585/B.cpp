#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<cctype>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (b<a) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

int T;
int N, K;
char F[3][111];
bool on[3][111], on2[3][111];

void phillip() {
    memset(on2, 0, sizeof on2);
    REP (i, 3) REP (j, N) if (on[i][j] && F[i][j+1] == '.') {
	REP (k, 3)
	    if (abs(i-k) <= 1 && F[k][j+1] == '.')
		on2[k][j+1] = true;
    }
    REP (i, 3) REP (j, N) on[i][j] = on2[i][j];
}

void train() {
    REP (i, 3) {
	REP (j, N) {
	    F[i][j] = F[i][j+1];
	    if (isupper(F[i][j])) on[i][j] = false;
	}
    }
}

int main() {
    scanf("%d", &T);
    REP ($, T) {
	scanf("%d%d", &N, &K);
	REP (i, 3) {
	    scanf("%s", F[i]);
	    F[i][N] = '.';
	}

	memset(on, 0, sizeof on);
	REP (i, 3) REP (j, N)
	    if (F[i][j] == 's') {
		on[i][j] = true;
		F[i][j] = '.';
	    }

	REP (i, N-1) {
	    phillip();
	    train();
	    train();
	}
	bool yes = false;
	REP (i, 3) if (on[i][N-1]) yes = true;
	puts(yes? "YES": "NO");
    }
    return 0;
}