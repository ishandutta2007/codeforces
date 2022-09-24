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

int N, A[100011], pos[100011];
int len[100011];

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i), A[i]--;
    REP (i, N) pos[A[i]] = i;

    int g = 1;
    len[0] = 1;
    for (int i=1; i<N; i++) {
	if (pos[i-1] < pos[i]) len[i] = len[i-1] + 1;
	else len[i] = 1;
	amax(g, len[i]);
    }

    printf("%d\n", N-g);

    return 0;
}