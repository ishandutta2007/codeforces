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

int N;
int A[111];
map<int, int> mp;
map<int, int> mem;

inline int bits(int x) { return (1 << x) - 1; }

int game(int mask) {
    mask &= -2;
    if (mask <= 1) return 0;

    auto it = mem.find(mask);
    if (it != mem.end()) {
	return it->second;
    }

    int g = __lg(mask);
    VI v;
    for (int i=1; i<=g; i++) {
	v.push_back(game((mask & bits(i)) | (mask >> i)));
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int ans = v.size();
    REP (i, v.size()) if (v[i] != i) {
	ans = i;
	break;
    }
    return mem[mask] = ans;
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    REP (i, N) {
	int a = A[i];
	for (int p=2; p*p<=a; p++) {
	    int cnt = 0;
	    while (a % p == 0) {
		a /= p;
		cnt++;
	    }
	    if (cnt) mp[p] |= 1 << cnt;
	}
	if (a > 1) mp[a] |= 2;
    }

    int nim = 0;
    EACH (e, mp) {
	int mask = e->second;
	nim ^= game(mask);
    }

    puts(nim? "Mojtaba" : "Arpa");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}