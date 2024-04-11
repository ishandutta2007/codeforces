#include<bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("no-stack-protector")

using namespace std;
const int inf = 1e9 + 7;
const int max_n = (1 << 19);



signed main() {
    //freopen("inpur.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int test;
    cin >> test;
    for(int q = 0;q < test;q++) {
        int n, m;
        string s;
        cin >> n >> m >> s;
        int pref[n];
        for(int i = 0;i < n;i++) pref[i] = 0;
        pref[n - 1] = 1;
        for(int i = 0;i < m;i++) {
            int p;
            cin >> p;
            pref[p - 1]++;
        }
        for(int i = n - 2;i >= 0;i--) pref[i] += pref[i + 1];
        int ans[26];
        for(int i = 0;i < 26;i++) ans[i] = 0;
        for(int i = 0;i < n;i++) {
            ans[(int)(s[i] - 'a')] += pref[i];
        }

        for(int i = 0;i < 26;i++) cout << ans[i] << " ";
        cout << '\n';
    }

}