#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

int n;
int h[N], b[N];
long long dp[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    // max dp, id
    vector<pair<long long, int>> st;
    dp[0] = 0;
    multiset<long long> s;

    for (int i = 1; i <= n; i++) {
        long long curMax = dp[i - 1];
        while (!st.empty() && h[i] < h[st.back().second]) {
            s.erase(s.find(st.back().first + b[st.back().second]));
            curMax = max(curMax, st.back().first);
            st.pop_back();
        }
        s.insert(curMax + b[i]);
        st.push_back({curMax, i});
        dp[i] = *s.rbegin();
    }

    cout << dp[n] << endl;
    return 0;
}