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

char S[300111];

int main() {
    scanf("%s", S);

    LL ans = 0;
    REP (i, strlen(S)) {
	int g = S[i] - '0';
	if (g % 4 == 0) ans++;
	if (i) {
	    g += (S[i-1] - '0') * 10;
	    if (g % 4 == 0) {
		ans += i;
	    }
	}
    }

    printf("%lld\n", ans);
	    
    return 0;
}