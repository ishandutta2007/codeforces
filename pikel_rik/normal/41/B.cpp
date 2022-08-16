#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef unsigned long long ull;
typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 5e5 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, b;
    cin >> n >> b;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int best = b;
    for (int i = 0; i < n; i++) {
        if (a[i] < b) {
            int m = -1;
            for (int j = i + 1; j < n; j++) m = max(m, a[j]);

            if (m <= a[i]) continue;

            int c = b / a[i];
            best = max(best, b - c * a[i] + c * m);
        }
    }

    cout << best << "\n";
    return 0;
}