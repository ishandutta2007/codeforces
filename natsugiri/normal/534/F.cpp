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

int N, M, A[9], B[21];
char F[9][33];
VI G[6];

int bs(int S) {
    bool prev = false;
    int cnt = 0;
    REP (i, N) {
	if (!prev && S&(1<<i)) cnt++;
	prev = (bool)(S&(1<<i));
    }
    return cnt;
}

int mem[161051][21];
bool rec(int col, const int S) {
    if (col == M) {
	REP (i, N) if (A[i]) return false;
	return true;
    }

    REP (i, N) if (A[i] < 0 || 2*A[i]-1 > M-col) return false;
    int st = 0;
    REP (i, N) st = st * 11 + A[i];
    if (mem[st][col] & (1u<<S)) return false;
    mem[st][col] |= (1u<<S);

    VI v = G[B[col]];
    random_shuffle(v.begin(), v.end());
    EACH (e, v) {
	REP (i, N) if (~S&(1<<i) && *e&(1<<i)) A[i]--;
	if (rec(col+1, *e)) {
	    REP (i, N) F[i][col] = (*e&(1<<i) ? '*': '.');
	    return true;
	}
	REP (i, N) if (~S&(1<<i) && *e&(1<<i)) A[i]++;
    }
    return false;
}

void test() {
//    srand(time(0));
    N = 5; M = 20;
    REP (i, N) REP (j, M) F[i][j] = ".*"[rand()%2];
    
    REP (i, N) {
	A[i] = 0;
	char p = '.';
	REP (j, M) {
	    if (p == '.' && F[i][j] == '*') A[i]++;
	    p = F[i][j];
	}
    }
    REP (j, M) {
	B[j] = 0;
	char p = '.';
	REP (i, N) {
	    if (p == '.' && F[i][j] == '*') B[j]++;
	    p = F[i][j];
	}
    }
    REP (i, N) eprintf("%s\n", F[i]); eprintf("--\n");
    memset(F, 0, sizeof F);
}

int main() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%d", A+i);
    REP (i, M) scanf("%d", B+i);
//    test();
    
    REP (S, 1<<N) G[bs(S)].push_back(S);
    
    rec(0, 0);
    REP (i, N) puts(F[i]);
    return 0;
}