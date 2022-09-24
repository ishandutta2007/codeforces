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
pair<int, int> P[100111];
int A[100111];

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d%d", &P[i].first, &P[i].second);
    sort(P, P+N);

    int ans = N;
    REP (i, N) {
	int left = P[i].first - P[i].second;
	int k = lower_bound(P, P + N, make_pair(left, -1)) - P;

	if (k == 0) A[i] = i;
	else A[i] = i - k + A[k-1];

	amin(ans, A[i] + N - i - 1);
    }

    printf("%d\n", ans);
    return 0;
}