#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, l, k;
string s;
string res[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> l >> k;
    cin >> s;
    sort(s.begin(), s.end());
    int lower = 1;
    int cur = 0;
    for (int i = 1; i <= l; i++) {
        for (int j = lower; j <= k; j++) {
            res[j] += s[cur++];
        }
        int newLower = k;
        while (newLower > lower && res[newLower - 1].back() == res[k].back()) newLower--;
        lower = newLower;
    }
    for (int i = 1; i <= n; i++) {
        while (res[i].size() < l) res[i] += s[cur++];
    }
    for (int i = 1; i <= n; i++) cout << res[i] << '\n';
    return 0;
}