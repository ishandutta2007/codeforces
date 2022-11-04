#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 1e5;

int arr[MAXN + 1];
ll aib[MAXN + 1];

inline void update(int pos, int n, int val) {
    for(int i = pos; i <= n; i += lsb(i)) {
        aib[i] += val;
    }
}

inline ll query(int pos) {
    ll ans = 0;
    for(int i = pos; i > 0; i -= lsb(i)) {
        ans += aib[i];
    }
    return ans;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    double inv = 0, exp = 0;
    for(i = 1; i <= n; i++) {
        inv += i - 1 - query(arr[i]);
        update(arr[i], n, 1);
    }
    memset(aib, 0, sizeof(aib));
    for(i = n; i >= 1; i--) {
        exp -= 1.0 * i * query(arr[i]);
        update(arr[i], n, n - i + 1);
    }
    for(int len = 1; len <= n; len++) {
        exp += 1.0 * len * (len - 1) * (n - len + 1) / 4.0;
    }
    cout << fixed << setprecision(20) << 2.0 * exp / (1.0 * n * (n + 1)) + inv;
    //cin.close();
    //cout.close();
    return 0;
}