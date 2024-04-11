#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef unsigned long long ull;
typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int c = 0;
    for (int a = 0; a <= m and a * a <= n; a++) {
        if ((n - a * a) * (n - a * a) == m - a) {
            c += 1;
        }
    }

    cout << c << "\n";
    return 0;
}