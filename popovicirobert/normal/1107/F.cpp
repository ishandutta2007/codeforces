#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MAXN = 500;

struct Data {
    int a, b, k;
    bool operator <(const Data &other) const {
        return b > other.b;
    }
}arr[MAXN + 1];

ll dp[MAXN + 1];


int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> arr[i].a >> arr[i].b >> arr[i].k;
    }
    sort(arr + 1, arr + n + 1);
    for(i = 1; i <= n; i++) {
        for(j = n - 1; j >= 0; j--) {
            dp[j + 1] = max(dp[j + 1], dp[j] + arr[i].a - 1LL * arr[i].b * j);
            dp[j] = max(dp[j], dp[j] + arr[i].a - 1LL * arr[i].b * arr[i].k);
        }
    }
    cout << *max_element(dp, dp + n + 1);
    //cin.close();
    //cout.close();
    return 0;
}