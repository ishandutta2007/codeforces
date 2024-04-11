#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

int maxSolve(vector<int> a, vector<int> b) {
    return min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);
}

int minSolve(vector<int> a, vector<int> b) {
    vector<pair<int, int>> v;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i - j != -1 and i - j != 2) {
                v.emplace_back(i, j);
            }
        }
    }

    int ans = INT_MAX;
    vector<int> tempa = a, tempb = b;
    do {
        a = tempa; b = tempb;
        for (auto& [i, j] : v) {
            int temp = min(a[i], b[j]);
            a[i] -= temp;
            b[j] -= temp;
        }
        ans = min(ans, maxSolve(a, b));
    } while (next_permutation(v.begin(), v.end()));
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];

    vector<int> b(3);
    cin >> b[0] >> b[1] >> b[2];

    cout << minSolve(a, b) << ' ' << maxSolve(a, b) << '\n';
    return 0;
}