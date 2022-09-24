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

const string vowels = "aeiouy";
int N, P[111];
char buf[1111];

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", P+i);
    scanf("\n");

    bool yes = true;

    REP (i, N) {
	scanf("%[^\n]\n", buf);
	int len = strlen(buf);
	int t = 0;
	REP (j, len) if (vowels.find(buf[j]) != vowels.npos) t++;

	if (t != P[i]) yes = false;
    }


    puts(yes? "YES": "NO");



    return 0;
}