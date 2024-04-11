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

    int n, s;
    cin >> n >> s;

    if (s < 2 * n) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    for (int i = 0; i < n - 1; i++)
        cout << "2 ";
    cout << s - 2 * (n - 1) << "\n" << "1\n";
    return 0;
}