#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(51);

#define ll long long
#define pb push_back
#define ld long double

vector<pair<int,int>> ans;

void rev(vector<int> &a, int l, int r) {
    ans.pb({l, r});
    reverse(a.begin() + l, a.begin() + r + 1);
    assert(a[l] == a[r]);
}

vector<int> solve(vector<int> a) {
    int n = a.size();
    map<int,int> ind;
    vector<int> nxt(n);
    for (int i = n - 1; i >= 0; i--) {
        if (ind.find(a[i]) != ind.end()) {
            nxt[i] = ind[a[i]];
        } else {
            ind[a[i]] = i;
            nxt[i] = -1;
        }
    }
    return nxt;
}

void solve(int n, vector<int> a, vector<int> b) {
    {
        map<pair<int,int>, int> cnt;
        for (int i = 0; i + 1 < n; i++) {
            cnt[{min(a[i], a[i + 1]), max(a[i], a[i + 1])}]++;
            cnt[{min(b[i], b[i + 1]), max(b[i], b[i + 1])}]--;
        }
        bool good = 1;
        for (auto to : cnt) {
            good &= (to.second == 0);
        }
        if (good && a[0] == b[0] && a.back() == b.back()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
            return;
        }
    }
    ans.clear();
    for (int i = 1; i + 1 < n; i++) {
        if (a[i] == b[i]) continue;
        pair<int,int> need{b[i], b[i - 1]};
        bool good = 0;
        vector<int> nxt = solve(a);
        for (int j = i; j + 1 < n; j++) {
            if (make_pair(a[j], a[j + 1]) == need) {
                rev(a, i - 1, j + 1);
                good = 1;
                break;
            } else if (make_pair(a[j + 1], a[j]) == need) {
                bool was = 0;
                for (int k = i - 1; k < j; k++) {
                    if (j + 1 <= nxt[k]) {
                        rev(a, k, nxt[k]);
                        was = 1;
                        break;
                    }
                }
                if (was) break;
            }
        }
        if (!good) {
            for (int j = i; j + 1 < n; j++) {
                if (make_pair(a[j], a[j + 1]) == need) {
                    rev(a, i - 1, j + 1);
                    break;
                }
            }
        }
    }
    cout << ans.size() << endl;
    for (auto to : ans) {
        cout << to.first + 1 << ' ' << to.second + 1 << endl;
    }
    assert(a == b);
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        solve(n, a, b);
    }
    return 0;
}