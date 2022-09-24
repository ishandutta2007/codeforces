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


int P[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 999 };
char buf[99];

int main() {
    int B = 1, cnt = 0;
    for (int i=0; cnt <= 1; ) {
	if (B * P[i] > 100) break;
	printf("%d\n", P[i] * B); fflush(stdout);
	scanf("%s", buf);
	if (buf[0] == 'y') {
	    B *= P[i];
	    cnt++;
	} else {
	    i++;
	}
    }


    if (cnt <= 1) puts("prime");
    else puts("composite");



    return 0;
}