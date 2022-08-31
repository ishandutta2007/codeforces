#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ull = unsigned long long;
using ll = long long;

const int mod = 210;
const int inf = 2e9 + 5;

int modexp(int x, int n) {
    if (n == 0)
        return 1;
    int ans = modexp((x * x) % mod, n / 2);
    if (n % 2)
        return (ans * x) % mod;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    if (n == 1 or n == 2) {
        cout << "-1\n";
        return 0;
    }

    if (n == 3) {
        cout << "210\n";
        return 0;
    }

    int num = modexp(10, n - 1);
    num = mod - num;

    cout << '1';
    int cnt;

    if (num >= 100) cnt = n - 4;
    else if (num >= 10) cnt = n - 3;
    else cnt = n - 2;

    for (int i = 0; i < cnt; i++) cout << '0';
    cout << num << "\n";

    return 0;
}