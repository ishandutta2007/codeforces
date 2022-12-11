#include <bits/stdc++.h>

using namespace std;

#define int long long
#define sz(x) ((int) (x).size())

int n;
vector<int> a;

int f(int n, int sum) {
    int x = sum - n * (n - 1) / 2;
    x = max(x, 0ll);
    return (x + n - 1) / n;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int sum = accumulate(a.begin(), a.end(), 0ll);
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        ans[i] = f(n - i, sum);
        if (i == 0) {
            ans[i] = max(ans[i], a[0]);
        } else {
            ans[i] = max(ans[i], ans[i - 1]);
        }
        sum -= ans[i];
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
}