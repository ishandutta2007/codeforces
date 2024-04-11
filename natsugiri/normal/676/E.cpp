#include<ctime>
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


int N, K;
char A[100111];
string X[100111];
LL Y[100111];
char buf[99];

bool yes() {
    int turn = N + 1 - count(A, A+N+1, '?');

    if (turn == N + 1) {
	REP (i, N+1) Y[i] = atoi(X[i].c_str());

	if (K == 1) {
	    LL sum = 0;
		REP (i, N+1) sum += Y[i];
	    return sum == 0;
	}


	srand(time(NULL));
	REP ($, 50) {
	    LL MOD = (LL)rand() * rand() % (1000000007) + 1000000007;
//	    eprintf("%lld\n", MOD);

	    LL sum = 0;
	    for (int i=N; i>=0; i--) {
		sum = (sum * K + Y[i]) % MOD;
	    }
	    if (sum < 0) sum += MOD;
	    if (sum != 0) return false;
	}
	return true;
    }

    if (K == 0) {
	if (A[0] == '0') return true;
	if (A[0] == '?' && turn % 2 == 1) return true;
	return false;
    } else {
	if (N % 2 == 1) return true;
	return false;
    }
}

int main() {
    scanf("%d%d", &N, &K);

    REP (i, N+1) {
	scanf("%s", buf);
	X[i] = buf;
	if (buf[0] == '0') A[i] = '0';
	else if (buf[0] == '-') A[i] = '-';
	else if (buf[0] == '?') A[i] = '?';
	else A[i] = '+';
    }

    puts(yes()? "Yes": "No");


    return 0;
}