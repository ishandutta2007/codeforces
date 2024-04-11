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
pair<int, int> P[500111];

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d%d", &P[i].second, &P[i].first);
    sort(P, P+N);
    int ans = 0;
    int last = -1;
    REP (i, N) {
	if (last < P[i].second) {
	    last = P[i].first;
	    ans++;
	}
    }
    printf("%d\n", ans);
    return 0;
}