#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }

string A;
char S[9999];

int C[1111];
int N, K;


int main() {
    scanf("%d%d", &N, &K);
    REP (i, N) {
	scanf("%s", S);
	int l = strlen(S);
	C[l]++;
    }
    scanf("%s", S);
    A = S;


    int mi = 0, ma = 0;
    int sum = 0, cnt = 0;

    REP (i, 1111) {
	if (i == (int)A.size()) {
	    mi = sum + 1;
	    if (cnt == K) mi += 5;
	}
	REP (j, C[i]) {
	    if (cnt == K) { sum += 5; cnt = 0; }
	    cnt++;
	    sum++;
	}

	if (i == (int)A.size()) {
	    ma = sum;
	    break;
	}
    }

    printf("%d %d\n", mi, ma);




    return 0;
}