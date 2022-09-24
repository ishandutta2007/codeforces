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

const char *POS = "Possible";
const char *AMB = "Ambiguity";
const char *IMP = "Impossible";

int N, M;
int A[100111], F[100111], B[100111];

int rF[100111];

int main() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%d", F+i), F[i]--;
    REP (i, M) scanf("%d", B+i), B[i]--;

    memset(rF, -1, sizeof rF);

    REP (i, N) {
	if (rF[F[i]] == -1) rF[F[i]] = i;
	else rF[F[i]] = -2;
    }

    bool yes = true;
    REP (i, M) {
	if (rF[B[i]] == -1) {
	    puts(IMP);
	    return 0;
	}

	A[i] = rF[B[i]];
	if (A[i] == -2) {
	    yes = false;
	}

    }


    if (yes) {
	puts(POS);
	REP (i, M) printf("%d%c", A[i]+1, i==M-1? '\n': ' ');
    } else {
	puts(AMB);
    }
    
    return 0;
}