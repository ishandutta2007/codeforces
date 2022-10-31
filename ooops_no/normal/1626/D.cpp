#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

const int INF = 1e18;

int get(int x) {
    int k = 0;
    while ((1LL << k) < x) k++;
    return (1LL << k) - x;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            mp[a]++;
        }
        vector<int> a{0};
        int cnt = 0;
        for (auto to : mp) {
            cnt += to.second;
            a.pb(cnt);
        }
        int ans = INF;
        for (int i = 0; i < a.size(); i++) {
            int res = get(a[i]), k = 0;
            for (int j = 0; j < 25; j++) {
                int l = i, r = a.size();
                while (r - l > 1) {
                    int mid = (r + l) / 2;
                    if (a[mid] - a[i] <= (1LL << j)) {
                        l = mid;
                    } else {
                        r = mid;
                    }
                }
                ans = min(ans, res + get(a[l] - a[i]) + get(a.back() - a[l]));
            }
        }
        cout << ans << endl;
    }
    return 0;
}