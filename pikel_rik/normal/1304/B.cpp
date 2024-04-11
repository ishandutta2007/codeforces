#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

bool f(const string& s) {
    for (int i = 0; i < s.length() / 2; i++) {
        if (s[i] != s[s.length() - i - 1])
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    vector<bool> visited(n);
    vector<pair<int, int>> pairs;
    for (int i = 0; i < n; i++) {
        if (visited[i])
            continue;
        for (int j = i + 1; j < n; j++) {
            if (visited[j])
                continue;
            reverse(s[j].begin(), s[j].end());
            if (s[i] == s[j]) {
                pairs.emplace_back(i, j);
                visited[j] = visited[i] = true;
            }
            reverse(s[j].begin(), s[j].end());
        }
    }

    string palindrome;
    for (int i = 0; i < n; i++) {
        if (!visited[i] and f(s[i])) {
            palindrome = s[i];
        }
    }

    for (auto& [i, j] : pairs) {
        palindrome = s[i] + palindrome + s[j];
    }

    cout << palindrome.length() << '\n';
    cout << palindrome << '\n';
    return 0;
}