#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n, m, k, t;
int a[N];

struct Trap {
    int l, r, d;
    bool operator < (const Trap &u) const {
        return l < u.l;
    }
} b[N];

bool check(int num) {
    vector<pair<int,int>> ls;
    for (int i = 1; i <= k; i++) {
        if (b[i].d <= num) continue;
        if (ls.empty() || ls.back().second < b[i].l) {
            ls.push_back({b[i].l, b[i].r});
        } else ls.back().second = max(ls.back().second, b[i].r);
    }
    long long tot = n + 1;
    for (auto u : ls) tot += 2ll * (u.second - u.first);
    return tot <= t;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n >> k >> t;
    for (int i = 1; i <= m; i++) cin >> a[i];
    sort(a + 1, a + m + 1);
    reverse(a + 1, a + m + 1);
    for (int i = 1; i <= k; i++) {
        cin >> b[i].l >> b[i].r >> b[i].d;
        b[i].l--;
    }
    sort(b + 1, b + k + 1);
    int low = 0, high = m + 1;
    while (high - low > 1) {
        int mid = low + high >> 1;
        if (check(a[mid])) low = mid;
        else high = mid;
    }
    cout << low << endl;
    return 0;
}