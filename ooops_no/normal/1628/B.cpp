#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

bool check(string s) {
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> s(n);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        bool ok = 0;
        for (int q = 0; q < 2; q++) {
            map<string, int> mp;
            for (int i = n - 1; i >= 0; i--) {
                string t = s[i];
                reverse(t.begin(), t.end());
                if (t == s[i] || mp[t]) {
                    ok = 1;
                } else {
                    if (s[i].size() == 3 && s[i][1] == s[i][2] && mp[s[i].substr(0, 1)]) {
                        ok = 1;
                    } else if (s[i].size() == 3) {
                        string k = s[i].substr(0, 2);
                        reverse(k.begin(), k.end());
                        if (mp[k]) {
                            ok = 1;
                        }
                    }
                }
                mp[s[i]] = 1;
            }
            reverse(s.begin(), s.end());
            for (int i = 0; i < n; i++) reverse(s[i].begin(), s[i].end());
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}