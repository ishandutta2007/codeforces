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


int N;

int main() {
    scanf("%d", &N);
    VI ans ;
    REP( i, N) {
	bool good = true;
	REP (j, N) {
	    int x;
	    scanf("%d", &x);
	    if (x == 1 || x == 3) good = false;
	}
	if (good) ans.push_back(i);
    }

    printf("%d\n", (int)ans.size());
    REP (i, ans.size()) printf("%d%c", ans[i]+1, i+1==(int)ans.size()? '\n': ' ');


    return 0;
}