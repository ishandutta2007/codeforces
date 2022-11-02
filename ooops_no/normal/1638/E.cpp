#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

const int INF = 1e9, N = 1e6 + 10;

struct Fenwick {
    vector<long long> t;
    Fenwick(int n) {
        t.resize(n);
    }
    void inc(int i, int d) {
        for (; i < t.size(); i = (i | (i + 1))) {
            t[i] += d;
        }
    }
    long long get(int r) {
        long long ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            ans += t[r];
        }
        return ans;
    }
} t(N);

set<pair<int,int>> seg;
map<pair<int,int>, int> color;
map<pair<int,int>, long long> bal;
unordered_map<int, long long> mp;

pair<int,int> get_seg(int i) {
    auto it = seg.lower_bound({i, INF});
    it--;
    return *it;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    seg.insert({0, n - 1});
    color[{0, n - 1}] = 1;
    for (int i = 0; i < q; i++) {
        string s;
        cin >> s;
        if (s == "Color") {
            int l, r, c;
            cin >> l >> r >> c;
            l--, r--;
            int L = l;
            while (l <= r) {
                pair<int,int> p = get_seg(l);
                int c = color[p];
                int a = mp[c], b = bal[p];
                t.inc(p.first, a - b);
                t.inc(p.second + 1, -(a - b));
                seg.erase(p);
                color.erase(p);
                bal.erase(p);
                if (p.first < L) {
                    seg.insert({p.first, L - 1});
                    color[{p.first, L - 1}] = c;
                    bal[{p.first, L - 1}] = a;
                }
                if (p.second > r) {
                    seg.insert({r + 1, p.second});
                    color[{r + 1, p.second}] = c;
                    bal[{r + 1, p.second}] = a;
                }
                l = p.second + 1;
            }
            seg.insert({L, r});
            color[{L, r}] = c;
            bal[{L, r}] = mp[c];
        } else if (s == "Add") {
            int c, x;
            cin >> c >> x;
            mp[c] += x;
        } else {
            int j;
            cin >> j;
            j--;
            pair<int,int> p = get_seg(j);
            int a = mp[color[p]], b = bal[p];
            t.inc(p.first, a - b);
            t.inc(p.second + 1, -(a - b));
            bal[p] = a;
            cout << t.get(j) << '\n';
        }
    }
    return 0;
}