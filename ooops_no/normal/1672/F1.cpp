#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll __int128
#define int long long

mt19937 rnd(51);

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        vector<vector<int>> pos(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
            pos[a[i]].pb(i);
        }
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int a, int b) {return pos[a].size() < pos[b].size();});
        for (int i = 0; i + 1 < n; i++) {
            for (int j = 0; j < pos[ord[i]].size(); j++) {
                b[pos[ord[i + 1]][j]] = ord[i] + 1;
            }
        }
        for (int i = 0; i < n; i++) {
            if (b[i] == 0) {
                b[i] = ord.back() + 1;
            }
        }
        for (auto to : b) cout << to << ' ';
        cout << endl;
    }
    return 0;
}