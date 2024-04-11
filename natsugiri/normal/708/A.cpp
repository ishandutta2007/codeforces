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


char S[100111];
int a, b;
int main() {
    scanf("%s", S);
    int n = strlen(S);
    a = -1;
    REP (i, n) if (S[i] != 'a') {
	a = i;
	break;
    }

    if (a == -1) {
	S[n-1] = 'z';
    } else {
	for (int i=a; i<n; i++) {
	    if (S[i] == 'a') {
		break;
	    } else {
		S[i]--;
	    }
	}
    }

    puts(S);


    return 0;
}