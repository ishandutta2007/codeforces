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


int f(LL x) { return (x % 2 + 2) % 2; }

int main() {
    LL x0, x1;
    LL y0, y1;
    scanf("%lld%lld", &x0, &y0);
    scanf("%lld%lld", &x1, &y1);

    LL ans = (y1-y0+1) * (x1-x0+1) / 2;

    // if ((f(x0) + f(x1) + f(y0) + f(y1)) % 4 == 0) ans++;
    if ((y1-y0) % 2 == 0) ans++;
    printf("%lld\n", ans);

    return 0;
}