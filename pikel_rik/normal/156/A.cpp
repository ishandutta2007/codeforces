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

    string s, u;
    cin >> s >> u;

    int n = s.length(), m = u.length();

    int best = m;
    for (int i = -m; i < n; i++) {
        int c = m;

        for (int j = 0; j < m && i + j < n; j++) {
            if (i + j >= 0 and s[i + j] == u[j])
                c -= 1;
        }

        best = min(best, c);
    }

    cout << best << "\n";
    return 0;
}