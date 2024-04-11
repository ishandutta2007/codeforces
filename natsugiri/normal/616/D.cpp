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

int N, K, A[500011], C[1000011];
pair<int, int> ans;
int main() {
    scanf("%d%d", &N, &K);
    REP (i, N) scanf("%d", A+i);
    int i = 0, j = 0, cur = 0;
    for (; i<N; i++) {
	if (C[A[i]] == 0) cur++;
	C[A[i]]++;

	while (cur > K) {
	    C[A[j]]--;
	    if (C[A[j]] == 0) cur--;
	    j++;
	}

	amax(ans, make_pair(i-j+1, j));
    }

    printf("%d %d\n", ans.second+1, ans.second+ans.first);
    return 0;
}