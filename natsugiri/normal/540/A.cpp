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

template<class T> inline void amin(T &a, const T &b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

int N;
char S[1111], T[1111];
int main() {
    scanf("%d%s%s", &N, S, T);
    int ans = 0;
    REP (i, N) {
	int d = abs((int)S[i] - T[i]);
	ans += min(d, 10 - d);
    }
    printf("%d\n", ans);
    return 0;
}