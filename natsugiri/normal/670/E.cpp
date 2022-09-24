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


int N, M, p;
char S[500111];
char op[500111];

int L[500111], R[500111];

int main() {
    scanf("%d%d%d", &N, &M, &p);
    scanf("%s", S+1);
    scanf("%s", op);
    S[0] = '(';
    S[N+1] = ')';

    REP (i, N+2) {
	L[i] = i-1;
	R[i] = i+1;
    }

    REP ($, M) {
	if (op[$] == 'L') {
	    p = L[p];
	} else if (op[$] == 'R') {
	    p = R[p];
	} else if (op[$] == 'D') {
	    int k = p;
	    int d = 0;

	    do {
		if (S[k] == '(') d++;
		else d--;

		if (S[p] == '(') k = R[k];
		else k = L[k];
	    } while (d);

	    if (S[p] == '(') {
		p = L[p];
		R[p] = k;
		L[k] = p;

		if (k != N+1) p = k;
	    } else {
		p = R[p];
		L[p] = k;
		R[k] = p;

		if (p == N+1) p = k;
	    }
	}
    }

    {
	int i = R[0];
	while (i != N+1) {
	    putchar(S[i]);
	    i = R[i];
	}
	putchar('\n');
    }



    return 0;
}