#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int N = 2e5 + 5;

string s, t;
int n, m, dp1[N], dp2[N];

bool f(int l) {
    bool ok = false;
    for (int i = 0; i + l <= n; i++) {
        int l1 = (i - 1 >= 0 ? dp1[i - 1] : 0), l2 = (i + l < n ? dp2[i + l] : 0);
        ok |= (l1 + l2) >= m;
    }
    return ok;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s >> t;
    n = s.length(), m = t.length();

    if (n == m) {
        cout << "0\n";
        return 0;
    }

    for (int i = 0, j = 0; i < n; i++) {
        dp1[i] = (i ? dp1[i - 1] : 0);
        if (j < m and s[i] == t[j]) {
            dp1[i]++;
            j++;
        }
    }

    for (int i = n - 1, j = m - 1; i >= 0; i--) {
        dp2[i] = (i + 1 < n ? dp2[i + 1] : 0);
        if (j >= 0 and s[i] == t[j]) {
            dp2[i]++;
            j--;
        }
    }

    int lo = 1, hi = n - m;
    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if (f(mid))
            lo = mid;
        else hi = mid - 1;
    }
    cout << lo << '\n';
    return 0;
}