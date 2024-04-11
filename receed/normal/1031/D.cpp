#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <random>
#include <ctime>
#include <iomanip>
#include <deque>
#include <queue> 
#include <cmath>
#include <cstring>
#include <cassert>
#include <bitset>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int N = 2002;
char a[N][N];
int dp[N][N], used[N][N];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#else
    //freopen("f.in", "r", stdin); 
    //freopen("f.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ms = 0;
    used[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0)
                dp[i][j] = 0;
            else if (i == 0)
                dp[i][j] = dp[i][j - 1];
            else if (j == 0)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
            dp[i][j] += (a[i][j] != 'a' ? 1 : 0);
            if (dp[i][j] <= k) {
                ms = max(ms, i + j + 1);
                if (i < n - 1)
                    used[i + 1][j] = 1;
                if (j < n - 1)
                    used[i][j + 1] = 1;
             }
        }
    }
    string ans(ms, 'a');
    for (int i = ms; i < 2 * n - 1; i++) {
        char mc = 'z';
        for (int j = 0; j < n; j++)
            if (0 <= i - j && i - j < n && used[j][i - j])
                mc = min(mc, a[j][i - j]);
        for (int j = 0; j < n; j++)
            if (0 <= i - j && i - j < n && used[j][i - j] && a[j][i - j] == mc) {
                if (j + 1 < n)
                    used[j + 1][i - j] = 1;
                if (i - j + 1 < n)
                    used[j][i - j + 1] = 1;
            }
        ans.push_back(mc);
    }
    cout << ans;
}