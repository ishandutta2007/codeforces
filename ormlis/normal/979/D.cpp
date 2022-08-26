#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1e5 + 1;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

vector<int> divs[maxN];

struct fenwick {
    vector<int> fenw{};
    int n{};

    void build(int k) {
        n = k;
        fenw.resize(n, 0);
    }

    void upd(int i) {
        for(; i < n; i = i | (i + 1)) fenw[i]++;
    }

    int get(int i) {
        int res = 0;
        for(; ~i; i = (i & (i + 1)) - 1) res += fenw[i];
        return res;
    }

    int get(int l, int r) {
        return get(r - 1) - get(l - 1);
    }
};

int find(vector<int> &a, fenwick &b, int x, int s) {
    int l = 0;
    int r = upper_bound(all(a), s - x) - a.begin();
    if (b.get(r-1) == 0) return -1;
    int current = 0;
    for(int i = 17; ~i; --i) {
        int c = (1 << i);
        int mid = lower_bound(a.begin() + l, a.begin() + r, current + c) - a.begin();
        if (c & x) {
            if (b.get(l, mid) == 0) {
                l = mid;
                current += c;
            } else {
                r = mid;
            }
        } else {
            if (b.get(mid, r) == 0) {
                r = mid;
            } else {
                l = mid;
                current += c;
            }
        }
    }
    return a[l];
}

void solve() {
    for (int i = 1; i < maxN; ++i)
            for (int j = i; j < maxN; j += i)
                divs[j].push_back(i);

    int q;
    cin >> q;
    map<int, vector<int>> mp;

    vector<vector<int>> req;

    range(time, q) {
        int t;
        cin >> t;
        if (t == 1) {
            int u;
            cin >> u;
            for (auto &x: divs[u]) mp[x].push_back(u);
            req.push_back({1, u});
        } else {
            int x, k, s;
            cin >> x >> k >> s;
            req.push_back({2, x, k, s});
        }
    }

    for (auto &x: mp) sort(all(x.second));

    map<int, map<int, int>> mp2;
    map<int, fenwick> mp3;

    for(auto &x: mp) {
        mp3[x.first].build(x.second.size());
        for(int i = x.second.size() - 1; ~i; --i) {
            mp2[x.first][x.second[i]] = i;
        }
    }

    for(auto &v: req) {
        if (v[0] == 1) {
            int u = v[1];
            for(auto &x: divs[u]) mp3[x].upd(mp2[x][u]++);
        } else {
            int x = v[1];
            int k = v[2];
            int s = v[3];
            if (x % k) {
                cout << "-1\n";
                continue;
            }
            cout << find(mp[k], mp3[k], x, s) << "\n";
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}