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

LL N;
int main() {
    scanf("%lld", &N);
    int d = 1;
    LL T = 1;
    LL ans = 0;

    while (N >= T*10) {
	ans += T*9*d;
	T *= 10;
	d++;
    }

    ans += (N - T + 1) * d;

    printf("%lld\n", ans);

    return 0;
}