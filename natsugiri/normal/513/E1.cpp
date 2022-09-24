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

template<class T> inline void amin(T &a, const T &b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }


int N, K, A[411];
int dp[411][2][4][2][51][51];
int INF;
const int FIRST = 0, NONE = 1, LAST = 2, END = 3;

int rec(int pos, int sgn, int s, int take, int skip, int an) {
    if (an > K) return -INF;
    if (s == END) {
	if (an + skip >= K) return 0;
	else return -INF;
    }
    if (pos == N) return -INF;

    int ssg = (sgn+1)/2;
    int &ans = dp[pos][ssg][s][take][skip][an];
    if (ans != INF) return ans;
    ans = -INF;

    int C = ((s == FIRST || s == LAST) ? 1 : 2);

    // cut
    if (s != LAST) {
	amax(ans, sgn*A[pos]*C + rec(pos+1, -sgn, NONE, 0, skip, an+1)); 
	amax(ans, sgn*A[pos]*C + rec(pos+1, -sgn, LAST, 0, skip, an+1)); 
    }
    if (s == LAST) 
	amax(ans, sgn*A[pos] + rec(pos+1, sgn, END, 0, skip, an+1));

    // seq
    amax(ans, sgn*A[pos]*C + rec(pos+1, sgn, s, 1, skip, an));


    if (!take)
	amax(ans, rec(pos+1, sgn, s, 0, min(skip+1, K), an));
    return ans;
}

int main() {
    scanf("%d%d", &N, &K);
    REP (i, N) scanf("%d", A+i);

    memset(&INF, 0x3f, sizeof INF);
    memset(dp, 0x3f, sizeof dp);
    int ans = max(
	    rec(0, 1, FIRST, 0, 0, 0),
	    rec(0, -1, FIRST, 0, 0, 0));

    printf("%d\n", ans);

    return 0;
}