#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<iostream>
#include<string>
#include<set>
#include<queue>
#include<random>

using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")

#define pb push_back
#define int long long
#define ld long double
#define ll long long

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        map<int, map<char, int>> cnt;
        for (int i = 0; i < s.size(); i++) {
            cnt[i % k][s[i]]++;
        }
        int ans = 0;
        for (int i = 0; i < k / 2; i++) {
            int p = k - i - 1;
            int mn = 1e18;
            for (int j = 'a'; j <= 'z'; j++) {
                mn = min(mn, 2 * (n / k) - cnt[i][j] - cnt[p][j]);
            }
            ans += mn;
        }
        if (k % 2 == 1) {
            int pp = n / k;
            k /= 2;
            int mn = 1e18;
            for (int j = 'a'; j <= 'z'; j++) {
                mn = min(mn, pp - cnt[k][j]);
            }
            ans += mn;
        }
        cout << ans << endl;
    }
    return 0;
}