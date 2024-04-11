#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define ll long long
#define pb push_back

mt19937 rnd(51);

const int N = 2e5 + 10;

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> m(n), k(n);
    for (int i = 0; i < n; i++){
        cin >> m[i] >> k[i];
    }
    ld bst = -1;
    vector<int> ans;
    for (int i = 1; i <= 22; i++){
        vector<ld> cnt(N);
        for (int j = 0; j < n; j++){
            if (i <= k[j]){
                cnt[m[j]] += 1.0;
            }
            else{
                cnt[m[j]] += (ld)k[j] / (ld)i;
            }
        }
        vector<pair<ld, int>> u;
        for (int j = 0; j < N; j++){
            u.pb({cnt[j], j});
        }
        sort(u.rbegin(), u.rend());
        ld anss = 0;
        int kol = i;
        vector<int> arr;
        for (auto to : u){
            anss += to.first;
            arr.pb(to.second);
            kol--;
            if (kol == 0) break;
        }
        if (anss > bst){
            bst = anss;
            ans = arr;
        }
    }
    cout << ans.size() << endl;
    for (auto to : ans) cout << to << ' ';
    cout << endl;
    return 0;
}