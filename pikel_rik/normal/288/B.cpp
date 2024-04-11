#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ull = unsigned long long;
using ll = long long;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

int n, k, arr[9], visited[9];

bool ok() {
    fill(visited, visited + 9, false);
    for (int i = 2; i <= k; i++) {
        int num = i;
        bool flag = false;

        for (int c = 0; c < k; c++) {
            if (visited[num] or num == 1) {
                flag = true;
                break;
            }
            visited[num] = true;
            num = arr[num];
        }
        if (!flag)
            return false;
    }
    return true;
}

ll modexp(int x, int n) {
    if (n == 0)
        return 1;
    ll ans = modexp((x * (ll)x) % mod, n / 2);
    if (n % 2)
        return (x * ans) % mod;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> k;
    int c = 0;

    for (int i = 0; i <= modexp(k, k - 1) - 1; i++) {
        int num = i;

        for (int j = 2; j <= k; j++) {
            arr[j] = num % k + 1;
            num /= k;
        }

        if (ok())
            c += 1;
    }

    cout << (c * modexp(n - k, n - k)) % mod;
    return 0;
}