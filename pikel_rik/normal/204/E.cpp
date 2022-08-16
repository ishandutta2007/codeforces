#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

template <typename T>
class FenwickTree {
public:
    using F = function<T(const T&, const T&)>;

    int n;
    vector<T> bit;
    F f;

    FenwickTree(): n(), bit(), f() {}
    FenwickTree(int n, F f = plus<T>()): n(n), bit(n + 1, 0), f(f) {}

    void add(int i, T val) {
        for (; i <= n; i += i & -i) {
            bit[i] = f(bit[i], val);
        }
    }
    T query(int i) {
        T ans = T();
        for (; i; i -= i & -i) {
            ans = f(ans, bit[i]);
        }
        return ans;
    }
};

vector<int> suffixArray(string s) {
    s += char(0);
    int n = s.length();
    vector<int> sa(n);
    vector<int> c(n), cnt(max(256, n));
    for (int i = 0; i < n; i++) {
        cnt[s[i]]++;
    }
    for (int i = 1; i < 256; i++) {
        cnt[i] += cnt[i - 1];
    }
    for (int i = 0; i < n; i++) {
        sa[--cnt[s[i]]] = i;
    }
    c[sa[0]] = 0;
    int classes = 1;

    for (int i = 1; i < n; i++) {
        if (s[sa[i]] != s[sa[i - 1]])
            classes++;
        c[sa[i]] = classes - 1;
    }

    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; h++) {
        for (int i = 0; i < n; i++) {
            pn[i] = (sa[i] + n - (1 << h)) % n;
        }

        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++) {
            cnt[c[pn[i]]]++;
        }
        for (int i = 1; i < classes; i++) {
            cnt[i] += cnt[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            sa[--cnt[c[pn[i]]]] = pn[i];
        }
        cn[sa[0]] = 0;
        classes = 1;

        for (int i = 1; i < n; i++) {
            if (c[sa[i]] != c[sa[i - 1]] or c[(sa[i] + (1 << h)) % n] != c[(sa[i - 1] + (1 << h)) % n]) {
                classes++;
            }
            cn[sa[i]] = classes - 1;
        }
        c.swap(cn);
    }
    sa.erase(sa.begin());
    return sa;
}

vector<int> LCP(const string& s, const vector<int>& sa) {
    int n = s.length();
    vector<int> lcp(n - 1), rank(n);
    for (int i = 0; i < n; i++) {
        rank[sa[i]] = i;
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = sa[rank[i] + 1];
        while (i + k < n && j + k < n && s[i + k] == s[j + k]) {
            k++;
        }
        lcp[rank[i]] = k;
        if (k) {
            k--;
        }
    }
    return lcp;
}

const int N = 1e5 + 5;

int n, k;
ll final[N], add[2 * N];
pair<int, int> id[2 * N];
string a[N];

int q, ans[2 * N], last[N], que[2 * N];
vector<pair<int, int>> queries[2 * N];

void addQuery(int l, int r, int i) {
    que[i] = q;
    queries[r].emplace_back(l, q++);
}

void processQueries(const vector<int>& sa) {
    FenwickTree<int> ft(sa.size());
    for (int r = 0; r < sa.size(); r++) {
        if (id[sa[r]].first != -1) {
            if (last[id[sa[r]].first] != -1) {
                ft.add(last[id[sa[r]].first] + 1, -1);
            }
            ft.add(r + 1, 1);
            last[id[sa[r]].first] = r;
        }
        for (auto& [l, i] : queries[r]) {
            ans[i] = ft.query(r + 1) - ft.query(l);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(last, -1, sizeof(last));
    memset(que, -1, sizeof(que));

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];

    if (k == 1) {
        for (int i = 0; i < n; i++) {
            cout << ((ll)a[i].length() * a[i].length() + a[i].length()) / 2 << ' ';
        }
        return 0;
    }

    string s = a[0];
    for (int i = 0; i < a[0].length(); i++) {
        id[i] = make_pair(0, i);
    }
    int cur = a[0].length() - 1;
    for (int i = 1; i < n; i++) {
        s += char('a' - 1) + a[i];
        id[++cur] = make_pair(-1, -1);
        for (int j = 0; j < a[i].length(); j++) {
            id[++cur] = make_pair(i, j);
        }
    }

    vector<int> sa = suffixArray(s);
    vector<int> lcp = LCP(s, sa);

    for (int i = 0; i < lcp.size(); i++) {
        if (id[sa[i]].first == -1 or id[sa[i + 1]].first == -1) {
            lcp[i] = 0;
        } else {
            auto[i1, j1] = id[sa[i]];
            auto[i2, j2] = id[sa[i + 1]];
            lcp[i] = min({lcp[i], (int) a[i1].length() - j1, (int) a[i2].length() - j2});
        }
    }

    vector<int> l(lcp.size(), -1), r(lcp.size(), lcp.size()), st;
    for (int i = 0; i < lcp.size(); i++) {
        while (!st.empty() and lcp[st.back()] >= lcp[i]) {
            st.pop_back();
        }
        if (!st.empty()) {
            l[i] = st.back();
        }
        st.push_back(i);
    }

    st.clear();
    for (int i = (int)lcp.size() - 1; i >= 0; i--) {
        while (!st.empty() and lcp[st.back()] >= lcp[i]) {
            st.pop_back();
        }
        if (!st.empty()) {
            r[i] = st.back();
        }
        st.push_back(i);
    }

    set<pair<int, int>> repeated;
    for (int i = 0; i < lcp.size(); i++) {
        if (id[sa[i]].first == -1 or id[sa[i + 1]].first == -1) continue;
        if (lcp[i] && !repeated.count(make_pair(l[i], r[i]))) {
            addQuery(l[i] + 1, r[i], i);
            repeated.emplace(l[i], r[i]);
        }
    }

    processQueries(sa);
    for (int i = 0; i < lcp.size(); i++) {
        if (que[i] != -1 && ans[que[i]] >= k) {
            int ad = lcp[i] - max(l[i] == -1 ? 0 : lcp[l[i]], r[i] == lcp.size() ? 0 : lcp[r[i]]);
            add[l[i] + 1] += ad;
            add[r[i] + 1] -= ad;
        }
    }

    ll cursum = 0;
    for (int i = 0; i < sa.size(); i++) {
        cursum += add[i];
        if (id[sa[i]].first != -1) {
            final[id[sa[i]].first] += cursum;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << final[i] << ' ';
    }
    cout << '\n';
    return 0;
}