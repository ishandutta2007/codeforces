#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define ld long double
#define ll __int128

mt19937 rnd(51);

bool bad(vector<int> a) {
    for (int i = 0; i + 2 < a.size(); i++) {
        if (a[i + 2] == a[i] + a[i + 1]) {
            return 1;
        }
    }
    return 0;
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<vector<int>, int> mp;
        vector<int> p(n);
        iota(p.begin(), p.end(), 1);
        for (int i = 0; i < n; i++) {
            while (mp.find(p) != mp.end() || bad(p)) {
                shuffle(p.begin(), p.end(), rnd);
            }
            mp[p] = 1;
            for (auto to : p) {
                cout << to << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}