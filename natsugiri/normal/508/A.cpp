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

const int dx[] = {0, 1, 0, 1};
const int dy[] = {0, 0, 1, 1};

int N, M, K;
bool F[1111][1111];

int main() {
    scanf("%d%d%d", &N, &M, &K);
    REP ($, K) {
	int x, y;
	scanf("%d%d", &y, &x);
	F[y][x] = true;
	bool ok = false;
	REP (s, 4) {
	    bool f = true;
	    int xx = x-dx[s], yy = y-dy[s];
	    REP (d, 4) if (!F[yy+dy[d]][xx+dx[d]]) f = false;
	    if (f) ok = true;
	}
	if (ok) {
	    printf("%d\n", $+1);
	    return 0;
	}
    }
    puts("0");
    return 0;
}