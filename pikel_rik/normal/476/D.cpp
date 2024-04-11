#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ull = unsigned long long;
using ll = long long;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    cout << k * (5 + 6 * (n - 1)) << "\n";

    for (int i = 1; i <= n; i++) {
        int num = 3 + 6 * (i - 1);
        cout << k * (num - 2) << " " << k * (num - 1) << " " << k * num << " " << k * (num + 2) << "\n";
    }
    return 0;
}