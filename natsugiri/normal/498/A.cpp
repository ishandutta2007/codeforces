#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0,i##_len=(n); i<i##_len; i++)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)

template<class T> inline void amin(T &a, const T &b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

LL HX, HY, UX, UY;
int N;

int sgn(LL n) {
    if (n < 0) return -1;
    if (n > 0) return 1;
    return 0;
}
int main() {
    scanf("%lld%lld%lld%lld", &HX, &HY, &UX, &UY);
    scanf("%d", &N);
    int cnt = 0;
    REP ($, N) {
	LL A, B, C;
	scanf("%lld%lld%lld", &A, &B, &C);
	if (sgn(A * HX + B * HY + C) != sgn(A * UX + B * UY + C)) cnt++;
    }

    printf("%d\n", cnt);

    return 0;
}