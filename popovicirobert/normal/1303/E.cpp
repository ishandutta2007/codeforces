#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define uint unsigned int


using namespace std;



int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, q;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> q;

    while(q--) {
        string s, t;
        cin >> s >> t;
        int ns = s.size(), nt = t.size();

        s = " " + s;
        t = " " + t;

        vector < vector <int> > dp(ns + 1, vector <int>(nt + 2));
        bool ans = 0;

        for(int k = 1; k <= nt && !ans; k++) {
            for(i = 0; i <= ns; i++) {
                fill(dp[i].begin(), dp[i].end(), -1);
            }

            dp[0][0] = 0;
            for(i = 0; i < ns; i++) {
                for(int j = 0; j <= k; j++) {
                    if(dp[i][j] == -1) continue;

                    if(j < k && s[i + 1] == t[j + 1]) {
                        dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
                    }
                    dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                    if(k + dp[i][j] + 1 <= nt && s[i + 1] == t[k + dp[i][j] + 1]) {
                        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + 1);
                    }
                }
            }

            ans |= (dp[ns][k] >= nt - k);
        }

        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}