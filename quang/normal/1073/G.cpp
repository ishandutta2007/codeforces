#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const int LOG = 20;

int n, q;
char s[N];
int sa[N], tmp[N], pos[N];
int len, cnt[N], lcp[N];
int rmq[LOG][N];

bool cmp(int u, int v) {
    if (pos[u] != pos[v]) {
        return pos[u] < pos[v];
    }
    return (u + len <= n && v + len <= n) ? pos[u + len] < pos[v + len] : u > v;
}

void radix(int delta) {
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= n; i++) {
        cnt[i + delta <= n ? pos[i + delta] : 0]++;
    }
    for (int i = 1; i < N; i++) {
        cnt[i] += cnt[i - 1];
    }
    for (int i = n; i > 0; i--) {
        int id = sa[i];
        tmp[cnt[id + delta <= n ? pos[id + delta] : 0]--] = id;
    }
    for (int i = 1; i <= n; i++) {
        sa[i] = tmp[i];
    }
}

void buildSA() {
    for (int i = 1; i <= n; i++) {
        sa[i] = i;
        pos[i] = s[i];
    }
    len = 1;
    while (1) {
        // radix(len);
        // radix(0);
        sort(sa + 1, sa + n + 1, cmp);
        tmp[1] = 1;
        for (int i = 2; i <= n; i++) {
            tmp[i] = tmp[i - 1] + cmp(sa[i - 1], sa[i]);
        }
        for (int i = 1; i <= n; i++) {
            pos[sa[i]] = tmp[i];
        }
        if (tmp[n] == n) {
            break;
        }
        len <<= 1;
    }
    len = 0;
    for (int i = 1; i <= n; i++) {
        if (pos[i] == n) {
            continue;
        }
        int j = sa[pos[i] + 1];
        while (s[i + len] == s[j + len]) {
            len++;
        }
        lcp[pos[i]] = len;
        if (len) {
            len--;
        }
    }
    for (int i = 1; i < n; i++) {
        rmq[0][i] = lcp[i];
    }
    for (int i = 1; i < LOG; i++) {
        for (int j = 1; j + (1 << i) - 1 < n; j++) {
            rmq[i][j] = min(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);
        }
    }
}

int getVal(int l, int r) {
    int lg = log2(r - l + 1);
    return min(rmq[lg][l], rmq[lg][r - (1 << lg) + 1]);
}

void compress(vector<pair<int, int> > &st, long long &curRes, int val) {
    pair<int, int> foo = {0, val};
    while (!st.empty()) {
        pair<int, int> now = st.back();
        if (now.second >= foo.second) {
            curRes -= 1ll * now.first * now.second;
            foo.first += now.first;
            st.pop_back();
        } else {
            break;
        }
    }
    if (foo.first > 0) {
        st.push_back(foo);
        curRes += 1ll * foo.first * foo.second;
    }
}

long long go(vector<int> &a, vector<int> &b, bool f) {
    int cur = 0;
    long long res = 0;
    long long curRes = 0;
    vector<pair<int, int> > st;
    // cout << "start " << endl;
    for (int i = 0; i < b.size(); i++) {
        if (!st.empty()) {
            assert(cur > 0);
            int foo = (a[cur - 1] == b[i] ? n - sa[a[cur - 1]] + 1 : getVal(a[cur - 1], b[i] - 1));
            compress(st, curRes, foo);
        }
        while (cur < a.size() && a[cur] < b[i]) {
            int foo = getVal(a[cur], b[i] - 1);
            st.push_back({1, foo});
            curRes += foo;
            compress(st, curRes, foo);
            cur++;
        }
        if (f && cur < a.size() && a[cur] == b[i]) {
            int foo = n - sa[a[cur]] + 1;
            st.push_back({1, foo});
            curRes += foo;
            compress(st, curRes, foo);
            cur++;
        }
        // for (auto u : st) {
        //     cout << u.first << " " << u.second << endl;
        // }
        // cout << curRes << endl;
        res += curRes;
    }
    return res;
}

int main() {
    scanf("%d %d", &n, &q);
    scanf("%s", s + 1);
    buildSA();
    while (q--) {
        int m[2];
        vector<int> a[2];
        cin >> m[0] >> m[1];
        for (int id = 0; id < 2; id++) {
            for (int i = 1; i <= m[id]; i++) {
                int u;
                cin >> u;
                a[id].push_back(pos[u]);
            }
        }
        sort(a[0].begin(), a[0].end());
        sort(a[1].begin(), a[1].end());
        long long res = 0;
        res += go(a[0], a[1], 0);
        res += go(a[1], a[0], 1);
        printf("%lld\n", res);
    }
    return 0;
}