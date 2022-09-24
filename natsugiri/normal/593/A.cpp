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
string W[111];
char buf[1111];
int main() {
    scanf("%d", &N);
    REP (i, N) {
	scanf("%s", buf);
	W[i] = buf;
    }

    int ans = 0;
    REP (i, 26) REP (j, i+1) {
	int gss = 0;
	REP (k, N) {
	    bool ok = true;
	    EACH (c, W[k]) if (*c != i+'a' && *c != j+'a') {
		ok = false;
		break;
	    }
	    if (ok) gss += W[k].size();
	}
	amax(ans, gss);
    }

    printf("%d\n", ans);
    return 0;
}