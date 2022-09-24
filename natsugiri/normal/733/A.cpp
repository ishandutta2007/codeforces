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

char S[1111];
int N;
string vowels = "AEIOUY";

int main() {
    scanf("%s", S);
    N = strlen(S);
    int last = -1;
    int ans = 0;
    REP (i, N) {
	if (vowels.find(S[i]) == vowels.npos) {
	} else {
	    amax(ans, i - last);
	    last = i;
	}
    }

    amax(ans, N - last);
    
    printf("%d\n", ans);




    return 0;
}