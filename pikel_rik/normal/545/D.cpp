#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ull = unsigned long long;
using ll = long long;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e5 + 1;

int n, t[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> t[i];

    sort(t, t + n);

    int sum = 0, c = 0;

    for (int i = 0; i < n; i++) {
        if (t[i] >= sum) {
            c += 1;
            sum += t[i];
        }
    }

    cout << c << "\n";
    return 0;
}