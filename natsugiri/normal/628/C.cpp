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

char S[100111];
int N, K;
int main() {
    scanf("%d%d%s", &N, &K, S);

    REP (i, N) {
	int a = S[i] - 'a';
	int z = 'z' - S[i];
	int t = K;
	if (a < z) {
	    amin(t, z);
	    S[i] += t;
	} else {
	    amin(t, a);
	    S[i] -= t;
	}
	K -= t;
    }

    if (K == 0) puts(S);
    else puts("-1");
    
    return 0;
}