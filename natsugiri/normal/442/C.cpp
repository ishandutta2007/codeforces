#include<set>
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

int N;
int A[500111];
pair<int, int> P[500111];
set<int> S;


int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    REP (i, N) {
	P[i] = make_pair(A[i], i);
	S.insert(i);
    }

    LL ans = 0;
    LL offset = 0;
    sort(P, P+N);
    REP (i, N-2) {
	LL height = P[i].first - offset;
	offset = P[i].first;
	ans += height * ((int)S.size() - 2);
	int k = P[i].second;
	set<int>::iterator it = S.find(k);
	if (it != S.begin()) {
	    int tmp = A[*prev(it)];
	    ++it;
	    if (it != S.end()) {
		amin(tmp, A[*it]);
		ans += tmp - offset;
	    }
	}
	S.erase(k);
    }

    printf("%lld\n", ans);


    return 0;
}