#include<assert.h>
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

int T;

char op[9], s[99];
int mem[1<<18];


int main() {
    scanf("%d", &T);
    REP ($, T) {
	scanf("%s %s", op, s);
	int l = strlen(s);

	int d = 0;
	REP (i, l) d = 2 * d + ((s[i] - '0') & 1);

	if (op[0] == '+') {
	    mem[d]++;
	} else if (op[0] == '-') {
	    mem[d]--;
	} else if (op[0] == '?') {
	    printf("%d\n", mem[d]);
	} else {
	    assert("NOPE" && false);
	}
    }


    return 0;
}