#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 5000 + 5;

void constructLcp(const string& s1, const string& s2, int lcp[N][N]) {
    int n = s1.length(), m = s2.length();
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (s1[i] == s2[j]) {
                lcp[i][j] = 1 + lcp[i + 1][j + 1];
            } else {
                lcp[i][j] = 0;
            }
        }
    }
}

int n, m, lcp[N][N], lcp1[N][N], lcp2[N][N], lcp_max1[N], lcp_max2[N];
string s1, s2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s1 >> s2;
    n = s1.length(), m = s2.length();

    constructLcp(s1, s2, lcp);
    constructLcp(s1, s1, lcp1);
    constructLcp(s2, s2, lcp2);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                lcp_max1[i] = max(lcp_max1[i], lcp1[i][j]);
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (i != j) {
                lcp_max2[i] = max(lcp_max2[i], lcp2[i][j]);
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (lcp[i][j]) {
                if (lcp[i][j] > max(lcp_max1[i], lcp_max2[j])) {
                    ans = min(ans, max(lcp_max1[i], lcp_max2[j]) + 1);
                }
            }
        }
    }

    cout << (ans != INT_MAX ? ans : -1) << '\n';
    return 0;
}