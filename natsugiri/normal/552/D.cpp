#include<cassert>
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<complex>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (b<a) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

typedef complex<LL> Point;
namespace std {
    bool operator <(const Point &x, const Point &y) {
	return real(x)!=real(y)?real(x)<real(y):imag(x)<imag(y);
    }
}

int N;
Point A[2011];


int main() {
    scanf("%d", &N);
    int x, y;
    REP (i, N) {
	scanf("%d%d", &x, &y);
	A[i] = Point(x, y);
    }

    LL ans = (LL)N*(N-1)*(N-2);
    REP (i, N) {
	vector<Point> S(A, A+N);
	S[i] = S[N-1];
	S.pop_back();
	REP (j, N-1) S[j] -= A[i];

	EACH (e, S) {
	    LL g = __gcd(abs(e->real()), abs(e->imag()));
	    *e /= g;
	    if (e->real() < 0 || (e->real() == 0 && e->imag() < 0)) *e *= -1;
	}
	sort(S.begin(), S.end());
	for (int i=0, j=0; i<(int)S.size(); i=j) {
	    while (j < (int)S.size() && S[i] == S[j]) j++;
	    ans -= (LL)(j-i)*(j-i-1);
	}
    }

    assert(ans % 6 == 0);
    ans /= 6;
    printf("%lld\n", ans);

    return 0;
}