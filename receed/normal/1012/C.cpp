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
typedef long long ll;
typedef long double ld;

using namespace std;


int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    scanf("%d", &n);
    vector<ll> a(n + 2);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    ll inf = 1e11;
    vector<vector<ll>> dp1(n + 2, vector<ll>(n + 1, inf)), dp2(n + 2, vector<ll>(n + 1, inf));
    dp1[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            dp1[i][j] = min(dp1[i][j], min(dp1[i - 1][j], dp2[i - 1][j]));
            if (a[i] > a[i + 1]) {
                dp1[i + 1][j + 1] = min(dp1[i + 1][j + 1], dp1[i - 1][j] + max(a[i - 1] - a[i] + 1, 0ll));
                if (i > 1)
                    dp1[i + 1][j + 1] = min(dp1[i + 1][j + 1], dp2[i - 1][j] + max(a[i - 2] - a[i], 0ll));
            }
            else {
                dp2[i + 1][j + 1] = min(dp2[i + 1][j + 1], dp1[i - 1][j] + max(a[i - 1] - a[i] + 1, 0ll) + a[i + 1] - a[i] + 1);
                if (i > 1)
                    dp2[i + 1][j + 1] = min(dp2[i + 1][j + 1], dp2[i - 1][j] + max(a[i - 2] - a[i], 0ll) + a[i + 1] - a[i] + 1);
            }
        }
    }
    for (int i = 1; i <= (n + 1) / 2; i++)
        printf("%lld ", min(min(dp1[n][i], dp2[n][i]), dp1[n + 1][i]));
}