#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;
    string s;
    cin >> s;

    lint ans = (1ll * N * (N + 1) / 2); // all substrings
    vector<pair<int, int>> interval;
    // AB...B, BA..A, A..AB, B..BA are the only bad substrings
    for (int i = 0; i < N; i++) {
        int cur = i;
        while (cur + 1 < N && s[cur + 1] == s[i]) {
            cur++;
        }
        interval.emplace_back(i, cur);
        i = cur;
    }
    ans -= N; // substring of length 1
    for (int i = 1; i < interval.size(); i++) { // type XYY...YY
        ans -= interval[i].second - interval[i].first + 1;
    }
    for (int i = 0; i < interval.size() - 1; i++) { // type YY.YYX
        ans -= interval[i].second - interval[i].first + 1;
    }
    ans += interval.size() - 1;

    cout << ans << "\n";
    return 0;
}