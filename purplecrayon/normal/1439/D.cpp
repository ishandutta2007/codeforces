#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 5e2+10, MOD = 1e9+7;

// how do we characterize good configurations?
// let's say we know the final locations of people
// how many ways can we form that
//
// add things from 1...m
//   L = number of filled spaces to the left
//   R = number of filled spaces to the right 
//
//   the number of ways is -> L + R + 2
//   the sum of the madness over all ways is L * (L + 1) / 2 + R * (R + 1) / 2
// 
// let's say m = n
// imagine the process backwards
//      removing something from position X splits it into two subproblems with some cost
//
// now you can split the original array into a bunch of runs which are complete
// for each run you need to know the number of ways to fill a segment of size x with y people

int M;

namespace mod_ops {
    #define MOD M
    int add_self(int& a, int b) {
        a += b;
        if (a >= MOD) a -= MOD;
        return a;
    }
    int add(int a, int b) {
        return add_self(a, b);
    }
    int sub_self(int& a, int b) {
        a -= b;
        if (a < 0) a += MOD;
        return a;
    }
    int sub(int a, int b) {
        return sub_self(a, b);
    }
    int mul(int a, int b) {
        return (long long) a * b % MOD;
    }
    void mul_self(int& a, int b) {
        a = mul(a, b);
    }
    int po(int b, int p) {
        int r = 1;
        for (; p; b = mul(b, b), p >>= 1) if (p&1) mul_self(r, b);
        return r;
    }
    int inv(int x) {
        return po(x, MOD-2);
    }
    int half(int x) {
        int HALF = (MOD + 1) / 2;
        return mul(x, HALF);
    }
    int di(int a, int b) {
        return mul(a, inv(b));
    }
    int di_self(int a, int b) {
        return a = di(a, b);
    }
    #undef MOD
};
using namespace mod_ops;

int n, m, C[MAXN][MAXN];
pair<int, int> dp[MAXN]; // {sum, cnt} if you have to entirely fill something of size x
pair<int, int> run[MAXN][MAXN];

void solve() {
    cin >> n >> m >> M;

    for (int i = 0; i <= n; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = add(C[i-1][j], C[i-1][j-1]);
        }
    }

    dp[0] = {0, 1};
    dp[1] = {0, 2}; // pick either left or right
    for (int i = 2; i <= n; i++) {
        dp[i] = make_pair(0, 0);
        for (int x = 0; x < i; x++) {
            int me_ways = i + 1;
            int cur_ways = mul(mul(dp[x].second, dp[i-1-x].second), me_ways);

            int cost = add( half(mul(x, x + 1)), half(mul(i-1-x, i-x)) );
            int cur_sum = 0;
            add_self(cur_sum, mul(dp[x].first, mul(me_ways, dp[i-1-x].second)));
            add_self(cur_sum, mul(dp[i-1-x].first, mul(me_ways, dp[x].second)));
            add_self(cur_sum, mul(cost, mul(dp[x].second, dp[i-1-x].second)));

            mul_self(cur_sum, C[i-1][x]);
            mul_self(cur_ways, C[i-1][x]);

            add_self(dp[i].first, cur_sum);
            add_self(dp[i].second, cur_ways);
        }
    }

    run[0][0] = {0, 1};
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            for (int x = 0; x <= j; x++) {
                int comb_ways = C[j][x];
                pair<int, int> prv = (i == x ? make_pair(0, 1) : run[i-x-1][j-x]);

                int cur_ways = dp[x].second;
                mul_self(cur_ways, mul(comb_ways, prv.second));

                int cur_sum = 0;
                add_self(cur_sum, mul(prv.first, dp[x].second));
                add_self(cur_sum, mul(prv.second, dp[x].first));
                mul_self(cur_sum, comb_ways);

                add_self(run[i][j].second, cur_ways);
                add_self(run[i][j].first, cur_sum);
            }
        }
    }
    cout << run[n][m].first << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}

// 0 1 1 1 -> 120
// 1 0 1 1 -> 24
// 1 1 0 1 -> 24
// 1 1 1 0 -> 120