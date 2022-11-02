#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long

mt19937 rnd(51);

const int N = 2e6 + 10;

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), all;
        map<int,int> mp;
        int mx = 0;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            mp[a[i]]++;
            mx = max(mx, mp[a[i]]);
        }
        if (mx >= n / 2){
            cout << -1 << endl;
            continue;
        }
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                int dif = abs(a[i] - a[j]);
                for (int k = 1; k * k <= dif; k++){
                    if (dif % k == 0){
                        all.pb(k);
                        all.pb(dif / k);
                    }
                }
            }
        }
        int ans = -1;
        for (auto i : all){
            int last = -1, mx = 0;
            map<int,int> cnt;
            for (auto to : a){
                int need = to % i;
                if (need < 0) need += i;
                cnt[need]++;
                mx = max(mx, cnt[need]);
            }
            for (auto to : a){
                int need = to % i;
                if (need < 0) need += i;
                cnt[need]--;
            }
            if (mx >= n / 2){
                ans = max(ans, i);
            }
        }
        cout << ans << endl;
    }
    return 0;
}