#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

const int MX = 4007;

struct Data {
    Data() {
        memset(f, 0, sizeof(f));
        x = 0;
        y = 0;
    }
    int f[MX];
    int x, y;
};

struct St {
    vector<Data> v;

    St() {
        v.push_back(Data());
    }

    void push(int x, int y) {
        v.push_back(Data());
        const auto& old = v[v.size() - 2];
        v.back().x = x;
        v.back().y = y;
        for (int i = MX - 1; i >= 0; i--) {
            v.back().f[i] = old.f[i];
            if (i >= x) {
                v.back().f[i] = max(v.back().f[i], old.f[i - x] + y);
            }
        }
        for (int i = 1; i < MX; i++) {
            v.back().f[i] = max(v.back().f[i], v.back().f[i - 1]);
        }
    }
};

St s1, s2;

void push(int x, int y) {
    s1.push(x, y);
}

void pop() {
    if (s2.v.size() == 1) {
        while (s1.v.size() > 1) {
            s2.push(s1.v.back().x, s1.v.back().y);
            s1.v.pop_back();
        }
    }
    s2.v.pop_back();
}


const int MT = 20 * 1000 + 7;

vector<pair<int, int> > ad[MT];
vector<pair<int, int> > reqs[MT];
int ans[MT];

int main() {
#ifdef FASTIO
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
    s1 = St();
    s2 = St();
    int n, p;
    cin >> n >> p;
    for (int i = 0; i < n; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        ad[t].emplace_back(x, y);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int t, c;
        cin >> t >> c;
        reqs[t].emplace_back(c, i);
    }

    for (int i = 0; i < MT; i++) {
        for (const auto& v : ad[i]) {
            push(v.first, v.second);
        }
        if (i >= p) {
            for (int j = 0; j < ad[i - p].size(); j++) {
                pop();
            }
        }
        for (const auto& v : reqs[i]) {
            int cost = v.first, id = v.second;
            int ans = 0;
            for (int j = 0; j <= cost; j++) {
                ans = max(ans, s1.v.back().f[j] + s2.v.back().f[cost - j]);
            }
            ::ans[id] = ans;
        }
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}