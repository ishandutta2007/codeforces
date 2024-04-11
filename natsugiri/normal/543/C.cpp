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

int N, M;
char S[21][33];
int A[21][21];
int X[1<<20], INF;

void test() {
    return;
    N = 20; M = 10;
    REP (i, N) REP (j, M) {
	S[i][j] = rand()%5 + 'a';
	A[i][j] = 1;
    }
}

int main() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%s", S[i]);
    REP (i, N) REP (j, M) scanf("%d", A[i]+j);

//    test();
    
    memset(X, 0x3f, sizeof X);
    memset(&INF, 0x3f, sizeof INF);
    X[0] = 0;
    
    REP (j, M) {
	REP (t, 26) {
	    char c = t + 'a';
	    VI v;
	    REP (i, N) if (S[i][j] == c) v.push_back(i);

	    if (v.size()) {
		int sum = 0, ma = 0, mask = 0;
		REP (k, v.size()) {
		    int i = v[k];
		    sum += A[i][j];
		    amax(ma, A[i][j]);
		    amin(X[1<<i], A[i][j]);
		    mask |= 1<<i;
		}
		amin(X[mask], sum - ma);
	    }
	}
    }


    VI cover, cost;
    REP (S, 1<<N) if (X[S] != INF) {
	cover.push_back(S);
	cost.push_back(X[S]);
    }
    REP (i, cost.size()) {
	REP (S, 1<<N) {
	    amin(X[S | cover[i]], X[S] + cost[i]);
	}
    }

    printf("%d\n", X[(1<<N)-1]);

    
    
    return 0;
}