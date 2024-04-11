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


int main() {
    int M;
    scanf("%d", &M);

    int i;
    for (i=5; M>=0;) {
	int k = i;
	while (k % 5 == 0) {
	    M--;
	    k /= 5;
	}
	if (M <= 0) break;
	i += 5;
    }

    if (M < 0) {
	puts("0");
    } else {
	puts("5");
	REP (j, 5) printf("%d%c", i+j, j==4?'\n':' ');
    }

    return 0;
}