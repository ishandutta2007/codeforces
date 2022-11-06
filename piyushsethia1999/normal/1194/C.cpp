#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

int dp[103][103];

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        string t; cin >> t;
        string p; cin >> p;
        memset(dp, -1, sizeof(dp));
        int m = s.size();
        int n = t.size();
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        if(dp[m][n] != m) {
            cout << "NO";
        } else {
            int freq[26] = {};
            for (int i = 0; i < s.size(); ++i) {
                freq[s[i] - 'a']++;
            }
            for (int i = 0; i < p.size(); ++i) {
                freq[p[i] - 'a']++;
            }
            for (int i = 0; i < t.size(); ++i) {
                freq[t[i] - 'a']--;
            }
            bool ok = true;
            for (int i = 0; i < 26; ++i) {
                if (freq[i] < 0) 
                    ok = false;
            }
            if (ok) {
                cout << "YES";
            } else {
                cout << "NO";
            }
        }
        cout << "\n";
    }
}