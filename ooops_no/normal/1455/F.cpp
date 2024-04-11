#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    int ttt;
    cin >> ttt;
    while(ttt--){
        int n, k;
        cin >> n >> k;
        k--;
        string s;
        cin >> s;
        vector<int> nxt(200), pref(200);
        for (int i = 'a'; i < 'a' + k; i++){
            nxt[i] = i + 1;
        }
        nxt['a' + k] = 'a';
        for (int i = 'a' + 1; i <= 'a' + k; i++){
            pref[i] = i - 1;
        }
        pref['a'] = 'a' + k;
        vector<vector<string>> dp(n, vector<string>(2));
        string t = "";
        for (int i = 0; i < n; i++){
            t += s[i];
        }
        dp[0][0] = (char)(min({(int)s[0], nxt[s[0]], pref[s[0]]}));
        if (n == 1){
            cout << dp[0][0] << endl;
            continue;
        }
        dp[1][0] = dp[0][0] + (char)(min({(int)s[1], nxt[s[1]], pref[s[1]]}));
        dp[1][0] = min(dp[1][0], s[1] + dp[0][0]);
        char c = (char)(min({(int)s[1], nxt[s[1]], pref[s[1]]}));
        string kkk = "";
        kkk += c;
        kkk += s[0];
        dp[1][0] = min(dp[1][0], kkk);
        dp[1][1] = dp[0][0] + s[2] + s[1];
        for (int i = 2; i < n; i++){
            string t = dp[i - 1][0] + (char)(min({(int)s[i], nxt[s[i]], pref[s[i]]}));
            string u = dp[i - 1][0] + s[i];
            swap(u[u.size() - 1], u[u.size() - 2]);
            t = min(t, u);
            string k = dp[i - 1][1];
            swap(k[k.size() - 1], k[k.size() - 2]);
            t = min(t, k);
            swap(k[k.size() - 1], k[k.size() - 2]);
            swap(k[k.size() - 2], k[k.size() - 3]);
            t = min(t, k);
            swap(k[k.size() - 2], k[k.size() - 3]);
            k[k.size() - 2] = (char)(min({(int)k[k.size() - 2], nxt[k[k.size() - 2]], pref[k[k.size() - 2]]}));
            t = min(t, k);
            dp[i][0] = t;
            if (i != n - 1){
                t = dp[i - 1][0] + s[i + 1] + s[i];
                dp[i][1] = t;
            }
        }
        cout << dp[n - 1][0] << endl;
    }
    return 0;
}