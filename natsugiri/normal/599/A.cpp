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

LL D[3][3];
int main() {
    memset(D, 0x3f, sizeof D);

    int x;
    scanf("%d", &x);
    D[0][1] = D[1][0] = x;
    scanf("%d", &x);
    D[0][2] = D[2][0] = x;
    scanf("%d", &x);
    D[1][2] = D[2][1] = x;
    REP (i, 3) D[i][i] = 0;

    REP (k, 3) REP (i, 3) REP (j, 3) amin(D[i][j], D[i][k] + D[k][j]);

    LL ans;
    ans = D[0][1] + D[1][2] + D[2][0];
    amin(ans, D[0][2] + D[2][1] + D[1][0]);
    printf("%lld\n", ans);
    return 0;
}