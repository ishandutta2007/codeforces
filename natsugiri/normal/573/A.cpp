#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (b<a) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

int N;
int A[100011];

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    int g = 0;
    REP (i, N) g = __gcd(g, A[i]);

    bool yes = true;
    REP (i, N) {
	A[i] /= g;
	for (int k=2; k<=3; k++) {
	    while (A[i] % k == 0) A[i] /= k;
	}
	if (A[i] > 1) {
	    yes = false;
	    break;
	}
    }

    puts(yes ? "Yes" : "No");
    
    return 0;
}