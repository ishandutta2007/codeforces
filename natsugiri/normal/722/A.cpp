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

char S[99];


int main() {


    int h;
    scanf("%d%s", &h, S);

    if (h == 12) {
	if (S[0] == '0') {
	    if (S[1] == '0') S[1] = '1'; // 01
	} else if (S[0] == '1') {
	    if (S[1] > '2') S[1] = '0'; // 10
	} else {
	    if (S[1] == '0') S[0] = '1'; // 10
	    else S[0] = '0'; // 0*
	}
    } else if (h == 24) {
	if (S[0] == '2') {
	    if (S[1] > '3') S[1] = '0'; // 20
	} else if (S[0] > '2') {
	    S[0] = '1'; // 1*
	}
    }

    if (S[3] > '5') S[3] = '0';

    puts(S);
    return 0;
}