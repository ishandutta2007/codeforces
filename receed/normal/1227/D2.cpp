#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

const int N = 1 << 18;
int tr[N * 2];

void add(int v) {
    for (int i = N + v; i; i /= 2)
        tr[i]++;
}

int kth(int k, int v=1, int l=0, int r=N) {
    if (r - l == 1)
        return l;
    if (tr[v * 2] >= k)
        return kth(k, v * 2, l, (l + r) / 2);
    return kth(k - tr[v * 2], v * 2 + 1, (l + r) / 2, r);
}
int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
    cin >> n;
    vector<int> fa(n);
    vector<pair<int, int>> a(n);
    rep(i, n) {
        cin >> fa[i];
        a[i].first = -fa[i];
        a[i].second = i;
    }
    sort(all(a));
    cin >> m;
    vector<vector<int>> q(m, vector<int>(3));
    rep(i, m) {
        cin >> q[i][0] >> q[i][1];
        q[i][2] = i;
    }
    vector<int> ans(m);
    sort(all(q));
    int p = 0;
    for (auto &pp : q) {
        while (p < pp[0]) {
            add(a[p].second);
            p++;
        }
        ans[pp[2]] = fa[kth(pp[1])];
    }
    rep(i, m)
        cout << ans[i] << '\n';
}