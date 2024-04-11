#include <bits/stdc++.h>
 
using namespace std;
 
using int64 = unsigned long long;
 
struct hash_table
{
    static const int64 M = (1LL << 40) - 1;
    static const int n = 30'000'000, mod = n - 3;
 
    int64 h[n];
    int f, p, c, link[n], last[mod];
 
    void init() { f = p = c = 0; memset(last, -1, sizeof last); }
    void clear() { for (int i = 0; i < c; ++i) last[(h[i] & M) % mod] = -1; f = p = c = 0; }
 
    int64* find(int64 hash)
    {
        for (f = -1, p = last[(hash & M) % mod]; p != -1; f = p, p = link[p])
            if ((h[p] & M) == (hash & M))
                return &h[p];
        return NULL;
    }
 
    void add(int64 hash) // require find
    {
        h[c] = hash;
        (hash &= M) %= mod;
        link[c] = last[hash];
        last[hash] = c++;
    }
} ht;
 
const int
    MaxX = 1,
    MaxY = 2,
    MinX = 3,
    MinY = 4;
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    ht.init();
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
 
        vector <vector <int>> s(n);
        vector <int> all;
 
        for(auto &o : s) {
            int l; cin >> l;
            o.assign(l, 0);
 
            for(auto &v : o) {
                cin >> v;
                all.push_back(v);
            }
        }
 
        sort(all.begin(), all.end());
        auto it = unique(all.begin(), all.end());
        all.erase(it, all.end());
 
        int m = all.size();
        vector <vector <int>> px(n), py(m);
        vector <pair <int, int>> pt;
        for(int i = 0; i < n; i++) {
            for(auto &x : s[i]) {
                x = lower_bound(all.begin(), all.end(), x) - all.begin();
                px[i].push_back(x);
                py[x].push_back(i);
                pt.push_back({i, x});
            }
        }
 
        for(auto &o : px)
            sort(o.begin(), o.end());
 
        for(auto &o : py)
            sort(o.begin(), o.end());
 
        ht.clear();
        pair <int, int> ans{-1, -1};
 
        auto doit = [&] (int x, int y, int wX, int wY) {
            if (ans.first != -1) return;
            pair <int, int> iX, iY;
 
            if(wX == MaxX) {
                int pos = upper_bound(px[x].begin(), px[x].end(), y) - px[x].begin();
                iX = { pos, px[x].size() };
            }
 
            else {
                int pos = lower_bound(px[x].begin(), px[x].end(), y) - px[x].begin();
                iX = { 0, pos };
            }
 
            if(wY == MaxY) {
                int pos = upper_bound(py[y].begin(), py[y].end(), x) - py[y].begin();
                iY = { pos, py[y].size() };
            }
 
            else {
                int pos = lower_bound(py[y].begin(), py[y].end(), x) - py[y].begin();
                iY = { 0, pos };
            }
 
            int szX = iX.second - iX.first;
            int szY = iY.second - iY.first;
 
            if(szX < szY) {
                for(int i = iX.first; i < iX.second; i++)
                {
                    int64 h = (int64)x << 40 | (int64)min(y, px[x][i]) << 20 | max(y, px[x][i]) | 1 << 19;
                    auto r = ht.find(h);
                    if (r != NULL && (*r >> 40) != x)
                    {
                        ans = { *r >> 40, x };
                        return;
                    }
                    if (r == NULL) ht.add(h);
                }
            }
            else {
                for(int i = iY.first; i < iY.second; i++)
                {
                    int64 h = (int64)y << 40 | (int64)min(x, py[y][i]) << 20 | max(x, py[y][i]);
                    auto r = ht.find(h);
                    if (r != NULL && (*r >> 40) != y)
                    {
                        ans = { x, py[y][i] };
                        return;
                    }
                    if (r == NULL) ht.add(h);
                }
            }
        };
 
        for(auto &[x, y] : pt) {
            doit(x, y, MaxX, MaxY);
            doit(x, y, MinX, MaxY);
            doit(x, y, MinX, MinY);
            doit(x, y, MaxX, MinY);
        }
 
        if(ans.first != -1) {
            cout << ans.first + 1 << " " << ans.second + 1 << "\n";
            continue;
        }
 
        cout << "-1\n";
    }
 
    return 0;
}