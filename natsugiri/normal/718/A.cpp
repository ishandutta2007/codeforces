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

int N, K;
char S[200111];

int main() {
    scanf("%d%d", &N, &K);
    scanf("%s", S);

    int p = 0;

    REP (i, N) if (S[i] == '.') p = i;

    for (int i=p+1; i<N; i++) {
	if (K == 0) break;

	if (S[i] >= '5') {
	    K--;
	    S[i] = 0;
	    N = i;
	    int c = 1;
	    int j = i-1;
	    for (; c && j>=p; j--) {
		if (S[j] == '9') {
		    S[j] = '0';
		    c = 1;
		} else {
		    S[j] ++;
		    c = 0;
		}
	    }
	    i = max(p, j-1);
	}
    }

    while (S[N-1] == '0') N--;

    int c = 0;
    if (S[p] != '.') {
	S[p] = 0;
	N = p;
	c = 1;
	for (int i=p-1; c && i>=0; i--) {
	    if (S[i] == '9') {
		S[i] = '0';
		c = 1;
	    } else {
		S[i]++;
		c = 0;
	    }
	}
    } else if (S[N-1] == '.') {
	S[N-1] = 0;
	N = N - 1;
    }


    if (c) putchar('1');
    puts(S);


    return 0;
}