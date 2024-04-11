#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(51);

#define ll long long
#define pb push_back
#define ld long double

const int INF = 1e9;

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        b = a;
        sort(b.begin(), b.end());
        int l = 0, r = INF + 1;
        while (r - l > 1) {
            int mid = (r + l) / 2;
            bool good = 0;
            for (int i = 0; i + 1 < n; i++) {
                int cnt = 0;
                if (a[i] < mid) cnt++;
                if (a[i + 1] < mid) cnt++;
                int need = (mid - 1) / 2;
                int j = upper_bound(b.begin(), b.end(), need) - b.begin();
                cnt += j;
                if (a[i] <= need) cnt--;
                if (a[i + 1] <= need) cnt--;
                if (cnt <= k) {
                    good = 1;
                    break;
                }
            }
            if (good) {
                l = mid;
            } else {
                r = mid;
            }
        }
        cout << l << endl;
    }
    return 0;
}