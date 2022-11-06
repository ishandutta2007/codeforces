#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

bool vis[11][1000];
int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
    for (int n = 0; n < 10; ++n) {
        for (int i = 0; i < (1 << n); ++i) {
            std::vector<int> v[2];
            for (int j = 0; j < n; ++j) {
                if (i & (1ll << j)) {
                    v[1].pb(j);
                } else {
                    v[0].pb(j);
                }
            }
            bool ok = true;
            for (int j = 0; j < v[0].size() && ok; ++j) {
                for (int k = j + 1; k < v[0].size() && ok; ++k) {
                    for (int l = k + 1; l < v[0].size() && ok; ++l) {
                        if (v[0][j] + v[0][l] == 2 * v[0][k]) {
                            ok = false;
                        } 
                    }
                }
            }
            for (int j = 0; j < v[1].size() && ok; ++j) {
                for (int k = j + 1; k < v[1].size() && ok; ++k) {
                    for (int l = k + 1; l < v[1].size() && ok; ++l) {
                        if (v[1][j] + v[1][l] == 2 * v[1][k]) {
                            ok = false;
                        } 
                    }
                }
            }
            vis[n][i] = ok;
        }
    }
    string s; cin >> s;
    int y = 0;
    for (int l = 1; l <= min(9ll, (int)s.size()); ++l) {
        int u = 0;
        int i = 0;
        while (i < l)
            u = u * 2 + s[i++] - '0'; 
        y += vis[l][u];
        for (; i < s.size(); ++i) {
            u = (u - (((int)(s[i - l] - '0')) << (l - 1))) * 2 + s[i] - '0';
            y += vis[l][u];
        }
    }
    int nn = s.size();
    cout << (nn * (nn + 1ll)) / 2ll - y;
}