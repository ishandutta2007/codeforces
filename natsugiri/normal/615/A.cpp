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

int N, M, A[111];
int main() {
    scanf("%d%d", &N, &M);
    REP (i, N) {
	int x, y;
	scanf("%d", &x);
	REP (j, x) {
	    scanf("%d", &y);
	    A[y-1] = 1;
	}
    }
    bool yes = true;
    REP (i, M) if (A[i] == 0) yes = false;
    puts(yes?"YES":"NO");
    return 0;
}