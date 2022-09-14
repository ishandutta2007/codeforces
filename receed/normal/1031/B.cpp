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

const int N = 100002;
int a[N], b[N], dp[N][4], p[N][4];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#else
    //freopen("f.in", "r", stdin); 
    //freopen("f.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < 4; i++)
        dp[0][i] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++) {
                if ((j | k) == a[i] && (j & k) == b[i] && dp[i - 1][j]) {
                    dp[i][k] = 1;
                    p[i][k] = j;
                }
            }
    }
    int f = -1;
    for (int i = 0; i < 4; i++)
        if (dp[n - 1][i])
            f = i;
    if (f == -1) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        ans[i] = f;
        f = p[i][f];
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
}