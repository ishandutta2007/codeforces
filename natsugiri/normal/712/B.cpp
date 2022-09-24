#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }


char S[100111];
int main() {

    scanf("%s", S);
    int len = strlen(S);

    int ans = -1;
    if (len % 2 == 0) {
	int bad = 
	    abs(count(S, S+len, 'L') - count(S, S+len, 'R')) +
	    abs(count(S, S+len, 'U') - count(S, S+len, 'D'));

	ans = bad / 2;
    }


    printf("%d\n", ans);

    return 0;
}