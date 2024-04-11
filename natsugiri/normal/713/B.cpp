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

// 160

int N;
char op[9];

VI ans;

void solve(int r1, int c1, int r2, int c2) {
    { // r1
	int l = r1, h = r2+1;
	while (h - l > 1) {
	    int m = (h + l) / 2;
	    printf("? %d %d %d %d\n", m, c1, r2, c2); fflush(stdout);
	    scanf("%s", op);
	    if (op[0] == '0') {
		h = m;
	    } else {
		l = m;
	    }
	}
	r1 = l;
    }
    { // c1
	int l = c1, h = c2+1;
	while (h - l > 1) {
	    int m = (h + l) / 2;
	    printf("? %d %d %d %d\n", r1, m, r2, c2); fflush(stdout);
	    scanf("%s", op);
	    if (op[0] == '0') {
		h = m;
	    } else {
		l = m;
	    }
	}
	c1 = l;
    }
    { // r2
	int l = r1-1, h = r2;
	while (h - l > 1) {
	    int m = (h + l) / 2;
	    printf("? %d %d %d %d\n", r1, c1, m, c2); fflush(stdout);
	    scanf("%s", op);
	    if (op[0] == '0') {
		l = m;
	    } else {
		h = m;
	    }
	}
	r2 = h;
    }
    { // c2
	int l = c1-1, h = c2;
	while (h - l > 1) {
	    int m = (h + l) / 2;
	    printf("? %d %d %d %d\n", r1, c1, r2, m); fflush(stdout);
	    scanf("%s", op);
	    if (op[0] == '0') {
		l = m;
	    } else {
		h = m;
	    }
	}
	c2 = h;
    }


    ans.push_back(r1);
    ans.push_back(c1);
    ans.push_back(r2);
    ans.push_back(c2);
}

int main() {
    scanf("%d", &N);

    int sep = -1;
    {
	int l = 0, h = N;

	while (h - l > 1) {
	    int m = (h + l) / 2;

	    printf("? 1 1 %d %d\n", N, m); fflush(stdout);
	    scanf("%s", op);

	    if (op[0] == '0') {
		l = m;
	    } else {
		h = m;
	    }
	}

	if (0 < h && h < N) {
	    printf("? 1 1 %d %d\n", N, h); fflush(stdout);
	    scanf("%s", op);
	    if (op[0] == '1') {
		printf("? 1 %d %d %d\n", h+1, N, N); fflush(stdout);
		scanf("%s", op);
		if (op[0] == '1') {
		    sep = h;
		}
	    }
	}
    }

    if (sep != -1) {
	solve(1, 1, N, sep);
	solve(1, sep+1, N, N);

    } else {
	int l = 0, h = N;

	while (h - l > 1) {
	    int m = (h + l) / 2;

	    printf("? 1 1 %d %d\n", m, N); fflush(stdout);
	    scanf("%s", op);

	    if (op[0] == '0') {
		l = m;
	    } else {
		h = m;
	    }
	}

	solve(1, 1, h, N);
	solve(h+1, 1, N, N);
    }

    printf("! ");
    REP (i, 8) printf("%d%c", ans[i], i==7?'\n':' ');
    fflush(stdout);

    return 0;
}