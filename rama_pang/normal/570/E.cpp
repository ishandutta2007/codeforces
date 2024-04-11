#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
int R, C;
char G[505][505];
long long F[505][505];
map<pair<pair<int, int>, int>, long long> memo;
map<pair<pair<int, int>, int>, bool> vis;

const long long MOD = 1e9 + 7;
long long cstep;
long long solve(int r1, int r2, int step) {
    int c1 = (cstep - step) - r1 + 1;
	int c2 = R + C - r2 - (cstep - step) + 1;
	if (r1 > r2 || c1 > c2) return 0;
    if (step == 0) return 1;
    // if (vis[{{r1, c1}, r2}]) return memo[{{r1, c1}, r2}];
    // vis[{{r1, c1}, r2}] = 1;
	long long res = 0;
	if (G[r1 + 1][c1] == G[r2 - 1][c2]) {
		res += solve(r1 + 1, r2 - 1, step - 1);
		res %= MOD;
	}
	if (G[r1][c1 + 1] == G[r2 - 1][c2]) {
		res += solve(r1, r2 - 1, step - 1);
		res %= MOD;
	}
    if (G[r1 + 1][c1] == G[r2][c2 - 1]) {
		res += solve(r1 + 1, r2, step - 1);
		res %= MOD;
	}
    if (G[r1][c1 + 1] == G[r2][c2 - 1]) {
		res += solve(r1, r2, step - 1);
		res %= MOD;
	}
    // memo[{{r1, c1}, r2}] = res;
	// cout << r1 << " " << c1 << " " << res << endl;
	return res;
}
long long solve2() {
    long long dp[505][505][3]; memset(dp, 0, sizeof(dp));
    for (int r1= 1; r1 <= R; r1++) {
        for (int r2 = 1; r2 <= R; r2++) {
            int c1 = (cstep) - r1 + 1;
            int c2 = R + C - r2 - (cstep) + 1;
            if (r1 > r2 || c1 > c2)
                dp[r1][r2][0] = 0;
            else
                dp[r1][r2][0] = 1;
        }
    }
    for (int step = 1; step < cstep; step++) {
        for (int r1 = 1; r1 <= R; r1++) {
            for (int r2 = 1; r2 <= R; r2++) {
                int c1 = (cstep - step) - r1 + 1;
                int c2 = R + C - r2 - (cstep - step) + 1;
                long long res = 0;
                int prev = (step + 1) % 2;
                if (r1 > r2 || c1 > c2) {dp[r1][r2][step % 2] = 0; continue;}
                if (G[r1 + 1][c1] == G[r2 - 1][c2]) {
                    res += dp[r1 + 1][r2 - 1][prev];
                    // res += solve(r1 + 1, r2 - 1, step - 1);
                    res %= MOD;
                }
                if (G[r1][c1 + 1] == G[r2 - 1][c2]) {
                    res += dp[r1][r2 - 1][prev];
                    // res += solve(r1, r2 - 1, step - 1);
                    res %= MOD;
                }
                if (G[r1 + 1][c1] == G[r2][c2 - 1]) {
                    res += dp[r1 + 1][r2][prev];
                    // res += solve(r1 + 1, r2, step - 1);
                    res %= MOD;
                }
                if (G[r1][c1 + 1] == G[r2][c2 - 1]) {
                    res += dp[r1][r2][prev];
                    // res += solve(r1, r2, step - 1);
                    res %= MOD;
                }
                dp[r1][r2][step % 2] = res;
            }
        }
        // for (int i = 1; i <= R; i++) {
        //     for (int j = 1; j <= R; j++) {
        //         cout << dp[i][j][1] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;   
    }

    return dp[1][R][(cstep + 1) % 2];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <=C; j++) {
			cin >> G[i][j];
		}
	}
    cstep = (R + C) / 2;
	cout << ((G[1][1] == G[R][C])? solve2() : 0)<< endl;
    // cout << ((G[1][1] == G[R][C])? solve(1, R, cstep - 1) : 0)<< endl;
    
}
/*
5 6
aaaaaa
aafaaa
aaaafa
aafaaa
aaaaaa
47
*/