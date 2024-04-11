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


int main() {
    scanf("%d", &N);
    LL ans = 0;
    LL c = 1;
    REP (i, 7) {
	c = c * (N-i) / (i+1);
	if (5 <= i+1 && i+1 <= 7) ans += c;
    }

    printf("%lld\n", ans);
    return 0;
}