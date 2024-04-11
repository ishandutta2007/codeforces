#include<cassert>
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
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

char buf[111];
string N[10] = {
    "no",
    "no",
    "no",
    "no",
    "no",
    "great!",
    "don't think so",
    "don't touch me!",
    "not bad",
    "cool",
};
string G[10] = {
    "no",
    "no",
    "no",
    "no way",
    "no way",
    "don't even",
    "are you serious?",
    "go die in a hole",
    "worse",
    "terrible",
};
    
string W[10];

bool match(string L[10], int len) {
//    REP (i, len) {
//	if (L+10 == find(L, L+10, W[i])) return false;
//    }
    int cur = 0;
    REP (i, 10) {
	if (cur < len && L[i] == W[cur]) cur++;
    }
    return cur == len;
}

void MAIN() {
    REP (i, 10) {
	while (!isalpha(N[i].back())) N[i].pop_back();
	while (!isalpha(G[i].back())) G[i].pop_back();
    }

    sort(N, N+10);
    sort(G, G+10);
    REP (i, 10) {
	printf("%d\n", i);
	fflush(stdout);
	scanf(" %[^\n]", buf);
//	eprintf("--%s--\n", buf);
	W[i] = buf;
	while (!isalpha(W[i].back())) W[i].pop_back();

	sort(W, W+i+1);

	bool nb = match(N, i+1);
	bool gb = match(G, i+1);
	if (nb && !gb) {
	    puts("normal");
	    return;
	} else if (!nb && gb) {
	    puts("grumpy");
	    return;
	} else if (!nb && !gb) {
	    for(;;);
	}
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    fflush(stdout);
    return 0;
}