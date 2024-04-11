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
#define eprintf(s...) fprintf(stderr, s)

int N;
char S[1111];
int main() {
    scanf("%d%s", &N, S);
    bool yes = false;
    REP (i, N) {
	for (int j=1; j<N; j++) {
	    int cnt = 0;
	    REP (k, 5) {
		int p = i + j * k;
		if (p < N && S[p] == '*') cnt++;
	    }
	    if (cnt == 5) yes = true;
	}
    }
    puts(yes? "yes": "no");
    return 0;
}