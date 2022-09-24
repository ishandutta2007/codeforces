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

int v1, v2, t, d;
int main() {
    scanf("%d%d%d%d", &v1, &v2, &t, &d);
    LL ans = 0;
    REP (i, t) {
	ans += v1;
	v1 = min(v1 + d, v2+d*(t-i-2));
    }
    printf("%lld\n", ans);
    return 0;
}