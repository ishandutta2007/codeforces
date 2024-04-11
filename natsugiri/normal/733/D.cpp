#include<tuple>
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

int N;
int A[100111], B[100111], C[100111];

typedef tuple<int, int, int, int> Four;

Four F[400111];
int ans;
int ansA, ansB;

void update(int a, int b, int c, int i) {
    if (a > b) swap(a, b);
    Four key(a, b, 1.5e9, 0);
    int pos = lower_bound(F, F + N * 3, key) - F;

    REP (_, 4) if (pos > 0) {
	pos--;
	const Four &f = F[pos];

	if (a == get<0>(f) && b == get<1>(f) && i != get<3>(f)) {
	    int tmp =  min({a, b, c + get<2>(f)});
	    if (ans < tmp) {
		ans = tmp;
		ansA = i;
		ansB = get<3>(f);
	    }
	}
    }
}

int main() {

    scanf("%d", &N);
    REP (i, N) scanf("%d%d%d", A+i, B+i, C+i);

    REP (i, N) {
	pair<int, int> p;
	
	p = minmax(A[i], B[i]);
	F[3 * i + 0] = Four(p.first, p.second, C[i], i);
	
	p = minmax(A[i], C[i]);
	F[3 * i + 1] = Four(p.first, p.second, B[i], i);

	p = minmax(B[i], C[i]);
	F[3 * i + 2] = Four(p.first, p.second, A[i], i);
    }
    
    sort(F, F + 3 * N);

    REP (i, N) {
	int tmp = min({A[i], B[i], C[i]});
	if (ans < tmp) {
	    ans = tmp;
	    ansA = i;
	    ansB = -1;
	}

	update(A[i], B[i], C[i], i);
	update(A[i], C[i], B[i], i);
	update(C[i], B[i], A[i], i);
    }

    if (ansB == -1) {
	printf("1\n%d\n", ansA+1);
    } else {
	printf("2\n%d %d\n", ansA+1, ansB+1);
    }
    return 0;
}