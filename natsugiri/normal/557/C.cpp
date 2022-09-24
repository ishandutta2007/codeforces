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
pair<int, int> P[100011];
int C[222];

int main() {

    scanf("%d", &N);
    REP (i, N) scanf("%d", &P[i].first);
    REP (i, N) scanf("%d", &P[i].second);

    sort(P, P+N);

    int cost = 0;
    REP (i, N) cost += P[i].second;
    int ans = 1<<29;

    for (int i=0, j=0; i<N; i=j) {
	while (j<N && P[j].first == P[i].first) {
	    cost -= P[j].second;
	    j++;
	}
	
	int al = j, le = j-i;
	int K = cost;
	int cnt = max(0, al - (le*2-1));

//	eprintf("%d %d - %d %d\n", P[i].first, al, le, cnt);
	REP (t, 201) {
	    int g = min(cnt, C[t]);
	    K += g * t;
	    cnt -= g;
	}

	amin(ans, K);
	for (; i<j; i++) C[P[i].second]++;
    }

    printf("%d\n", ans);

    return 0;
}