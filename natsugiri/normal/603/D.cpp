#include<map>
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


int N;
int sz = 0;
LL A[2011], B[2011], D[2011];
int Zero;

int main() {
    scanf("%d", &N);
    REP (i, N) {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if (c == 0) Zero++;
	else {
	    D[sz] = a*a + b*b;
	    A[sz] = a*c;
	    B[sz] = b*c;
	    sz++;
	}
    }


    LL ans = 0;
    if (Zero == 2) ans += N-2;

    REP (i, sz) {
	vector<pair<LL, LL> > v;

	REP (j, sz) if (j != i) {
	    LL real = A[i] * D[j] - A[j] * D[i];
	    LL imag = B[i] * D[j] - B[j] * D[i];

	    if (real > 0) {
		LL g = __gcd(abs(real), abs(imag));
		
		real /= g; imag /= g;
		v.push_back(make_pair(real, imag));
	    } else if (real == 0 && imag > 0) {
		v.push_back(make_pair(-1, -1));
	    }
	}

	sort(v.begin(), v.end());
	for (int i=0; i<(int)v.size(); ) {
	    int j;
	    for (j=i+1; j<(int)v.size() && v[i] == v[j]; j++) ;
	    LL t = j-i;
	    ans += t * (t-1) / 2;
	    i = j;
	}
    }
    
    printf("%lld\n", ans);

    
    return 0;
}