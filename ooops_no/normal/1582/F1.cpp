#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

const int N = 1025;

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    vector<int> ok(N, n);
    ok[0] = -1;
    for (int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    for (auto to : a){
        for (int j = 0; j < N; j++){
            if (ok[j] < to.second){
                ok[j ^ to.first] = min(ok[j ^ to.first], to.second);
            }
        }
    }
    vector<int> ans;
    for (int i = 0; i < N; i++) if (ok[i] != n) ans.pb(i);
    cout << ans.size() << endl;
    for (auto to : ans) cout << to << ' ';
    cout << endl;
    return 0;
}