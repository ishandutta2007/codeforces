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

char S[1000111];

int main() {
    scanf("%s", S);

    int dot = strlen(S);
    REP (i, strlen(S)) if (S[i] == '.') dot = i;
    if (dot == (int)strlen(S)) {
	S[dot] = '.';
	S[dot+1] = 0;
    }

    int f = strlen(S);
    REP (i, strlen(S)) if ('1' <= S[i] && S[i] <= '9') {
	f = i;
	break;
    }

    if (f == (int)strlen(S)) {
	puts("0");
    } else {
	int B = 0;
	while (f + 1 < dot) {
	    swap(S[dot], S[dot-1]);
	    dot--;
	    B++;
	}
	while (dot < f - 1) {
	    swap(S[dot], S[dot+1]);
	    dot++;
	    B--;
	}
	if (dot == f - 1) {
	    swap(S[dot], S[f]);
	    dot++;
	    f--;
	    B--;
	}
	
	// strip
	int l = strlen(S);
	while (S[l-1] == '0') {
	    S[l-1] = 0;
	    l--;
	}
	if (S[l-1] == '.') {
	    S[l-1] = 0;
	    l--;
	}

	printf("%s", S + f);
	if (B) printf("E%d\n", B);
	else puts("");

    }

    return 0;
}