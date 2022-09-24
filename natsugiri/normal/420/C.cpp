#include<map>
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

int N, P;
int X[300111], Y[300111];
int C[300111];
int D[300111];
map<pair<int, int>, int> mp;

int main() {
    scanf("%d%d", &N, &P);
    REP (i, N) {
	scanf("%d%d", X+i, Y+i);
	X[i]--; Y[i]--;
	if (X[i] > Y[i]) swap(X[i], Y[i]);
	C[X[i]]++;
	C[Y[i]]++;
	mp[make_pair(X[i], Y[i])]++;
    }

    LL ans = 0;

    REP (i, N) D[i] = C[i];
    sort(D, D+N);
    int k = N-1;
    REP (i, N-1) {
	amax(k, i);
	while (i < k && D[i] + D[k] >= P) k--;
	ans += N - 1 - k;
    }

    EACH (e, mp) {
	int x = e->first.first, y = e->first.second;
	int c = C[x] + C[y];
	if (c >= P && c - e->second < P) ans--;
    }
    printf("%lld\n", ans);

    return 0;
}