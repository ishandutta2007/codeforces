#include<bits/stdc++.h>

using namespace std;

typedef long long ftype;

const int N = 110;
const ftype mod = 998244353;

int n, m;
vector < pair < ftype, ftype > > segments_on[N][2], decomp_a[N][2];

void dfs_a(int h, ftype L, ftype R, ftype l, ftype r, int w) {
    if(L >= l && R <= r) {
        decomp_a[h][w].emplace_back(L, R);
        return;
    }
    if(l > R || r < L) return;
    ftype mid = (L + R) >> 1;
    dfs_a(h - 1, L, mid, l, r, w);
    dfs_a(h - 1, mid + 1, R, l, r, w);
}

void dfs_b(int h, ftype L, ftype R, ftype l, ftype r, int w) {
    if(l > R || r < L) return;
    segments_on[h][w].emplace_back(L, R);
    if(L >= l && R <= r) return;
    ftype mid = (L + R) >> 1;
    dfs_b(h - 1, L, mid, l, r, w);
    dfs_b(h - 1, mid + 1, R, l, r, w);
}

ftype calc(ftype x) {
    ftype y = x + 1;
    if(x % 2) y /= 2;
    else x /= 2;
    return (x % mod) * (y % mod) % mod;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if(fopen("inp", "r")) freopen("inp", "r", stdin);

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        ftype L, R; cin >> L >> R;
        dfs_a(60, 0, (1LL << 60) - 1, L, R, 0);
        dfs_b(60, 0, (1LL << 60) - 1, L, R, 1);
    }

    cin >> m;
    for(int i = 1; i <= m; ++i) {
        ftype L, R; cin >> L >> R;
        dfs_a(60, 0, (1LL << 60) - 1, L, R, 1);
        dfs_b(60, 0, (1LL << 60) - 1, L, R, 0);
    }

    vector < pair < ftype, ftype > > ans;
    for(int i = 0; i <= 60; ++i) {
        for(int t = 0; t < 2; ++t) {
            for(auto p : segments_on[i][t]) {
                for(auto q : decomp_a[i][t]) {
                    ftype pref = (p.first ^ q.first) >> i;
                    ans.emplace_back(pref << i, (pref << i) + (1LL << i) - 1);
                }
            }
        }
    }

    sort(ans.begin(), ans.end());

    ftype risan = 0;

    ftype last = -1;
    for(auto p : ans) {
        p.first = max(p.first, last);
        if(p.first > p.second) continue;
        risan += calc(p.second) - calc(p.first - 1);
        risan += mod;
        last = p.second + 1;
        risan %= mod;
    }

    cout << risan;

    return 0;
}