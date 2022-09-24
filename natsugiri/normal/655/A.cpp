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

char S[99];

int main() {
    REP (i, 4) scanf("%s", S + 2 * i);
    swap(S[2], S[3]);
    swap(S[6], S[7]);

    string a, b;
    REP (i, 4) {
	if (S[i] == 'A') {
	    REP (j, 4) {
		if (S[(i+j)%4] != 'X') a.push_back(S[(i+j)%4]);
	    }
	}
	if (S[i+4] == 'A') {
	    REP (j, 4) {
		if (S[(i+j)%4 + 4] != 'X') b.push_back(S[(i+j)%4 + 4]);
	    }
	}
    }

    puts(a == b? "YES" : "NO");



    return 0;
}