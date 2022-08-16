#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto& i : a) cin >> i;

        int c = accumulate(a.begin(), a.end(), 0);

        if (c > n / 2) {
            int temp = n / 2 + (n / 2) % 2;
            cout << temp << '\n';
            for (int i = 0; i < temp; i++) cout << "1 ";
        } else {
            int temp = n / 2;
            cout << temp << '\n';
            for (int i = 0; i < temp; i++) cout << "0 ";
        }
        cout << '\n';
    }
    return 0;
}