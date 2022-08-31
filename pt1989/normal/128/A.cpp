#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<bitset>
#include<complex>
 
#include<sstream>
#include<fstream>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<climits>
 
#define oo            (int)13e7
#define s(n)          scanf("%d",&n)
#define sl(n)         scanf("%lld",&n)
#define sf(n)         scanf("%lf",&n)
#define fill(a,v)     memset(a, v, sizeof a)
#define ull           unsigned long long
#define ll            long long
#define bitcount      __builtin_popcount
#define all(x)        x.begin(), x.end()
#define pb( z )       push_back( z )
#define gcd           __gcd
using namespace std;
char a[10][10];
vector<int> col[11];
int sx, sy, ex, ey;
const int mxt = 3000;
int dp[10][10][mxt];
int solve(int px, int py, int t) {
    if (px < 0 || py < 0 || px >= 8 || py >= 8)
        return 0;
    if (t >= mxt) return 0;
    for (int i=0; i < col[py].size(); i++) {
        if (col[py][i] + t == px)
            return 0;
        if (t)
        if (col[py][i] + t-1 == px)
            return 0;
    }
    if (px == ex && py == ey)
        return 1;
    int &ret = dp[px][py][t];
    if (~ret) return ret;
    ret = 0;
    for (int dx=-1; dx <= 1; dx++)
    for (int dy=-1; dy <= 1; dy++)
    if (1) {
        if (solve(px+dx, py+dy, t+1)) {
            return ret=1;
        }
    }
    return ret=0;
}

int main(int argc, char** argv) {
	for (int i=0; i < 8; i++) {
        scanf("%s", a[i]);
        for (int j=0; j < 8; j++) {
            if (a[i][j] == 'M') {
                sx = i; sy = j;
            } else if (a[i][j] == 'A') {
                ex = i; ey = j;
            } else if (a[i][j] == 'S') {
                col[j].pb( i );
            }
        }
    }
    fill(dp, -1);
    puts (solve(sx, sy, 0) ? "WIN" : "LOSE");
	return 0;
}