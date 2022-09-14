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
int dp[2][N];
int tr[N * 2], mod[N * 2];

void push(int v) {
    tr[v] += mod[v];
    if (v < N) {
        mod[v * 2] += mod[v];
        mod[v * 2 + 1] += mod[v];
    }
    mod[v] = 0;
}
void rel(int v) {
    tr[v] = max(tr[v * 2], tr[v * 2 + 1]);
}

void add(int cl, int cr, int d, int v=1, int l=0, int r=N) {
    if (cr <= l || r <= cl) {
        push(v);
        return;
    }
    if (cl <= l && r <= cr) {
        mod[v] += d;
        push(v);
        return;
    }
    push(v);
    add(cl, cr, d, v * 2, l, (l + r) / 2);
    add(cl, cr, d, v * 2 + 1, (l + r) / 2, r);
    rel(v);
}

int get(int v) {
    int res = tr[N + v];
    for (int i = N + v; i; i /= 2)
        res += mod[i];
    return res;
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n, mp = 0;
    cin >> n;
    deque<int> a(n);
    rep(i, n) {
        cin >> a[i];
        a[i]--;
        if (a[i] == 0)
            mp = i;
    }
    rep(i, mp) {
        a.push_back(a[0]);
        a.pop_front();
    }
    a.pop_front();
    rep(z, 2) {
        vector<int> st {-1};
        memset(tr, 0, N * 2 * sizeof(int));
        memset(mod, 0, N * 2 * sizeof(int));
        rep(i, n - 1) {
            while (st.size() > 1 && a[st.back()] > a[i])
                st.pop_back();
            add(st.back() + 1, i, 1);
            add(i, i + 1, st.size() == 1 ? 1 : get(st.back()) + 1);
            dp[z][i + 1] = tr[1];
            st.push_back(i);
        }
        reverse(all(a));
    }
    int ans = n + 1, res = 0, ca;
    rep(i, n) {
        ca = max(dp[0][i], dp[1][n - 1 - i]) + 1;
        if (ca < ans) {
            ans = ca;
            res = i;
        }
    }
    cout << ans << ' ' << (res + 1 + mp) % n;
}