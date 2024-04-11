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


char S[100011];
char T[100011];
int main() {
    scanf("%s%s", S,T);
    int cnt = 0;
    for (int i=0; S[i]; i++) { if (S[i] != T[i]) cnt++; }

    if (cnt & 1) {
	puts("impossible");
	return 0;
    }

    for (int i=0; S[i]; i++) {
	if (S[i] != T[i]) {
	    if (cnt) {
		cnt-=2;
	    } else {
		S[i] ^= 1;
	    }
	}
    }

    puts(S);



    return 0;
}