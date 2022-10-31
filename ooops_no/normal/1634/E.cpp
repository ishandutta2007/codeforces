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
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    vector<vector<char>> ans(n);
    vector<set<int>> b(n);
    map<int, set<pair<int,int>>> pos;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        ans[i].resize(k);
        a[i].resize(k);
        map<int, vector<int>> mp;
        for (int j = 0; j < k; j++) {
            cin >> a[i][j];
            mp[a[i][j]].pb(j);
        }
        for (auto to : mp) {
            vector<int> arr = to.second;
            while (arr.size() >= 2) {
                int j = arr.back();
                arr.pop_back();
                int k = arr.back();
                arr.pop_back();
                ans[i][j] = 'L', ans[i][k] = 'R';
            }
            if (arr.size() == 1) {
                pos[to.first].insert({i, arr[0]});
                b[i].insert(arr[0]);
            }
        }
    }
    bool f = 1;
    for (auto to : pos) {
        if (to.second.size() % 2 == 1) {
            f = 0;
        }
    }
    if (!f) {
        cout << "NO\n";
        return 0;
    }
    for (int i = 0; i < n; i++) {
        while (b[i].size() > 0) {
            int j = *b[i].begin();
            int val = a[i][j];
            b[i].erase(j);
            pos[val].erase({i, j});
            ans[i][j] = 'L';
            while (1) {
                int k = pos[val].begin()->first, j = pos[val].begin()->second;
                pos[val].erase({k, j});
                b[k].erase(j);
                ans[k][j] = 'R';
                if (k == i) {
                    break;
                } else {
                    j = *b[k].begin();
                    val = a[k][j];
                    pos[val].erase({k, j});
                    b[k].erase(j);
                    ans[k][j] = 'L';
                }
            }
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}