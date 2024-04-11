#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n;
char s[N];
vector<pair<char, int>> a;
int cnt[30];

struct BIT {
    int t[N];

    void add(int x, int v) {
        while (x < N) {
            t[x] += v;
            x += x & -x;
        }
    }

    int get(int x) {
        int res = 0;
        while (x) {
            res += t[x];
            x -= x & -x;
        }
        return res;
    }

    void init() {
        fill(t, t + n + 1, 0);
    }
} t;

struct DSU {
    int nxt[N], used[N];
    void init() {
        fill(used, used + n + 1, 0);
        iota(nxt, nxt + n + 1, 1);
        nxt[n + 1] = n + 1;
        used[n + 1] = 0;
    }
    int getNxt(int u) {
        return used[u] ? nxt[u] = getNxt(nxt[u]) : u;
    }
} dsu;

int getType(char u, int x) {
    return u == x + 'a';
}

pair<int, int> get(int l, int r) {
    int ll = l - t.get(l - 1);
    int rr = r - t.get(r - 1);
    // cout << "here " << l << ' ' << r << ' ' << ll << ' ' << rr << endl;
    int cur = dsu.getNxt(l);
    while (cur <= r) {
        t.add(cur, 1);
        dsu.used[cur] = 1;
        // cout << "cur " << cur << endl;
        cur = dsu.getNxt(cur);
    }
    return {ll, rr};
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> (s + 1);
        n = strlen(s + 1);
        
        a.clear();
        int sum = 0;
        memset(cnt, 0, sizeof cnt);
        dsu.init();
        t.init();

        for (int i = 1; i < n; i++) {
            if (s[i] == s[i + 1]) {
                a.push_back({s[i], i});
                cnt[s[i] - 'a']++;
                sum++;
            }
        }

        vector<pair<int, int>> res;
        vector<pair<char, int>> st;
        set<int> used;
        for (auto u : a) {
            if (sum <= 2 * *max_element(cnt, cnt + 26)) break;
            if (st.empty() || st.back().first == u.first) st.push_back(u);
            else {
                used.insert(u.second);
                used.insert(st.back().second);
                res.push_back(get(st.back().second + 1, u.second));
                sum -= 2;
                cnt[st.back().first - 'a']--;
                cnt[u.first - 'a']--;
                st.pop_back();
            }
        }

        st.clear();
        int id = max_element(cnt, cnt + 26) - cnt;
        for (auto u : a) {
            if (used.count(u.second)) continue;
            if (st.empty() || getType(st.back().first, id) == getType(u.first, id)) st.push_back(u);
            else {
                used.insert(st.back().second);
                used.insert(u.second);
                res.push_back(get(st.back().second + 1, u.second));
                st.pop_back();
            }
        }
        for (auto u : a) {
            if (used.count(u.second)) continue;
            res.push_back(get(1, u.second));
        }
        res.push_back(get(1, n));
        cout << res.size() << '\n';
        for (auto u : res) cout << u.first << ' ' << u.second << '\n';
    }   
    return 0;
}