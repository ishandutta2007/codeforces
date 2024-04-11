#include <bits/stdc++.h>


using namespace std;
//#define int long long
#define pii pair<int,int>
#define AIDAR ASADULLIN


signed main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)cin >> a[i];
    long long ans = 0;
    int mask = 0;
    int x = 0;
    for (int k = 29; k >= 0; k--) {
        long long val0 = 0;
        long long val1 = 0;
        vector<tuple<int, int, int>> v;
        for (int i = 0; i < n; i++) {
            v.emplace_back(a[i] & mask, i , (a[i] & (1 << k)) != 0);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j < n && get<0>(v[i]) == get<0>(v[j]))j++;
            int cnt = 0;
            int cnt1 = 0;
            for (int l = j - 1; l >= i; l--) {
                if (get<2>(v[l]) == 1) {
                    cnt1++;
                    val0 += cnt;
                } else {
                    cnt++;
                    val1 += cnt1;
                }
            }
            i = j - 1;
        }
        if (val0 <= val1) {
            ans += val0;
        } else {
            ans += val1;
            x += (1 << k);
        }
        mask += (1 << k);
    }
    cout << ans << " " << x;
}