#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define ld double
#define ll __int128

mt19937 rnd(51);

const int N = 1e5 + 10;
int po[30][N];

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), p(n), ind(n, -1);
    vector<set<int>> mp(n);
    vector<bool> in(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
        in[p[i]] = 1;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        if (a[i] < n) ind[a[i]] = i;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!in[i]) {
            cnt++;
        }
    }
    int val = (*max_element(a.begin(), a.end()) + 1 - n) / cnt;
    for (int i = 0; i < n; i++) {
        po[0][i] = p[i];
    }
    for (int i = 1; i < 30; i++) {
        for (int j = 0; j < n; j++) {
            po[i][j] = po[i - 1][po[i - 1][j]];
        }
    }
    for (int i = 0; i < n; i++) {
        int pos = i, res = val;
        for (int j = 29; j >= 0; j--) {
            if (res - (1 << j) >= 0) {
                pos = po[j][pos];
                res -= (1 << j);
            }
        }
        mp[pos].insert(i);

    }
    vector<int> ans(n), res(n);
    set<int> emp;
    for (int i = 0; i < n; i++) {
        if (ind[i] != -1) {
            ans[*mp[ind[i]].begin()] = i;
            mp[ind[i]].erase(*mp[ind[i]].begin());
            for (auto to : mp[ind[i]]) emp.insert(to);
        } else {
            ans[*emp.begin()] = i;
            emp.erase(*emp.begin());
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << ' ';
    }
    cout << endl;
    return 0;
}