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

int N, L[100111], R[100111];

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d%d", L+i, R+i);

    int sum = 0;
    REP (i, N) sum += L[i] - R[i];

    int cost = abs(sum), pos = 0;
    REP (i, N) {
	int tmp = sum + 2 * (R[i] - L[i]);
	if (abs(tmp) > cost) {
	    cost = abs(tmp);
	    pos = i + 1;
	}
    }
    printf("%d\n", pos);

    return 0;
}