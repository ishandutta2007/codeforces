#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

vector<int> solve(const string& s) {
    int n = s.length() + 1;
    vector<int> a(n);
    int cur = 1;

    int len = 0;
    for (int i = n - 2; i >= 0; i--) {
        if (s[i] == '<') {
            len++;
        } else {
            for (int j = 1; j <= len; j++) {
                a[i + j] = cur++;
            }
            len = 0;
        }
    }
    for (int j = 0; j < len; j++) {
        a[j] = cur++;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (!a[i]) {
            a[i] = cur++;
        }
    }
    return a;
}

vector<int> solve2(const string& s) {
    int n = s.length() + 1;
    vector<int> a(n);

    int cur = 1;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '<') {
            a[i] = cur++;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (!a[i]) {
            a[i] = cur++;
        }
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        vector<int> a = solve(s);
        for (int i : a) cout << i << ' '; cout << '\n';

        a = solve2(s);
        for (int i : a) cout << i << ' '; cout << '\n';
    }
    return 0;
}