#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)
template<class T> void sort_unique(vector<T> &v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}

VI ans;
void calc(int A, int B) {
    int S = A+B;
    int As = (S+1)/2;
    int Bs = S-As;
    
    for (int Ab=0; Ab<=Bs && Ab<=A; Ab++) {
	int Bb = As + Ab - A;
	if (0 <= Bb && Bb <= As && Bb <= B) {
	    ans.push_back(Ab+Bb);
	}
    }
}

void MAIN() {
    int A, B;
    scanf("%d%d", &A, &B);

    ans.clear();
    calc(A, B);
    calc(B, A);
    sort_unique(ans);
    printf("%d\n", (int)ans.size());
    rprintf("%d", ans.begin(), ans.end());
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}