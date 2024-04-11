#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<bitset>

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
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

LL N;

//using Bits = bitset<8>;
//
//bool use[1000011];
//void test() {
//    int a = 1;
//    REP (t, 30) {
//        while (use[a]) a++;
//        int b = a+1;
//        while (1) {
//            int c = a ^ b;
//            if (use[b] || use[c]) b++;
//            else {
//        	use[a] = use[b] = use[c] = true;
//		assert(b < c);
//		printf("%d %d %d ", a, b, c);
//        	//printf("%s %s %s\n",
//        	//	Bits(a).to_string().c_str(),
//        	//	Bits(b).to_string().c_str(),
//        	//	Bits(c).to_string().c_str());
//        	break;
//            }
//        }
//    }
//}

void MAIN() {
    scanf("%lld", &N);
    LL ans = 0;
    if (N <= 3) {
	ans = N;
    } else {
	N -= 4;
	int shift = 2;
	LL len = 4;
	while (1) {
	    if (N < len * 3) {
		LL a = 0, b = 0;
		a |= 1LL << shift;
		b |= 2LL << shift;
		while (shift) {
		    len /= 4;
		    shift -= 2;
		    if (N < len * 3) {

		    } else if (N < len * 3 * 2) {
			N -= len * 3;
			a |= 1LL << shift;
			b |= 2LL << shift;
		    } else if (N < len * 3 * 3) {
			N -= len * 3 * 2;
			a |= 2LL << shift;
			b |= 3LL << shift;
		    } else {
			N -= len * 3 * 3;
			a |= 3LL << shift;
			b |= 1LL << shift;
		    }
		}

		assert(N < 3);
		if (N == 0) ans = a;
		if (N == 1) ans = b;
		if (N == 2) ans = a ^ b;
		break;
	    } else {
		N -= len * 3;
		shift += 2;
		len *= 4;
	    }
	}
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}