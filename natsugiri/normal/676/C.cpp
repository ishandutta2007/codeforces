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
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }

int N, K;
char S[100111];

int calc(char c) {
    int i = 0, j = 0, z = 0;
    int ans = 0;
    for (; j<N;) {
	if (S[j] != c) z++;
	j++;
	while (z > K) {
	    if (S[i] != c) z--;
	    i++;
	}

	amax(ans, j - i);
    }

    return ans;
}

int main() {
    scanf("%d%d", &N, &K);
    scanf("%s", S);

    int ans = max(
	    calc('a'),
	    calc('b'));
    printf("%d\n", ans);


    return 0;
}