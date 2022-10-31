#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

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
        vector<int> a(n), cnt(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        int now = 0;
        vector<int> ans;
        map<int,int> mp;
        for (int i = 0; i < n; i++) {
            cnt[a[i]]--;
            mp[a[i]] = 1;
            while (mp[now]) {
                now++;
            }
            if (cnt[now] == 0) {
                ans.pb(now);
                mp.clear();
                now = 0;
            }
        }
        cout << ans.size() << endl;
        for (auto to : ans) {
            cout << to << ' ';
        }
        cout << endl;
    }
    return 0;
}