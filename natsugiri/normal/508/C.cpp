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


int M, T, R, W[333];
bool use[999];
int Z[999];
int main() {
    scanf("%d%d%d", &M, &T, &R);
    REP (i, M) scanf("%d", W+i);

    if (M && T < R) {
	puts("-1");
	return 0;
    }
    
    REP (i, M) {
	W[i] += 333;
	int k=W[i];
	while (Z[W[i]] < R) {
	    if (k < 0) {
		puts("-1");
		return 0;
	    }
	    if (!use[k]) {
		REP (j, T) Z[k+j]++;
		use[k] = true;
	    }
	    k--;
	}
    }

    int cnt = 0;
    REP (i, 999) if (use[i]) cnt++;
    printf("%d\n", cnt);
    return 0;
}