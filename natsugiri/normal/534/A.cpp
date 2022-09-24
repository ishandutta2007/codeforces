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
int main() {
    scanf("%d", &N);
    if (N == 1 || N == 2) {
	printf("1\n"
	       "1\n");
    } else if (N == 3) {
	printf("2\n"
	       "1 3\n");
    } else {
	printf("%d\n", N);
	int p = N/2+1, q = 1;
	REP (i, N) {
	    if (i & 1) printf("%d", q++);
	    else  printf("%d", p++);
	    printf("%c", i+1==N? '\n': ' ');
	}
    }
    return 0;
}