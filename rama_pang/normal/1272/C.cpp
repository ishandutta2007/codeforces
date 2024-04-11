#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    lint N, K;
    cin >> N >> K;
    string s;
    cin >> s;
    map<char, int> mp;
    for (int i = 0; i < K; i++) {
        string a; cin >> a;
        mp[a[0]]++;
    }

    vector<lint> A;
    A.emplace_back(0);
    for (int i = 0; i < N; i++) {
        if (mp.count(s[i]) == 0) {
            A.emplace_back(0);
            continue;
        }
        A.back()++;
    }

    lint ans = 0;
    for (auto i : A) {
        ans += (1ll * i * (i + 1)) / 2;
    }
    cout << ans << "\n";
    return 0;
}