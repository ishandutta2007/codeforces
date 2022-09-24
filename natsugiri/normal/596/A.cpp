#include<set>
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
int X[9], Y[9];
int xi, xa, yi, ya;
int main() {
    scanf("%d", &N);
    REP (i, N) {
	scanf("%d%d", X+i, Y+i);
    }
    set<int> xx(X, X+N);
    set<int> yy(Y, Y+N);
    if (xx.size() == 2u && yy.size() == 2u) printf("%d\n", (*xx.rbegin()-*xx.begin())*(*yy.rbegin()-*yy.begin()));
    else puts("-1");
    return 0;
}