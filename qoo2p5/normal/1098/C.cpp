#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

const int INF = (int) (1e9 + 1e6 + 123);
const ll LINF = (ll) (1e18 + 1e9 + 123);
const ll MOD = (ll) (1e9 + 7);

void run();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    run();
    return 0;
}

const int N = (int) 1e5 + 123;

int n;
set<int> g[N];
int p[N];
int h[N];
ll cnt[N];

ll get_minimal(int k) {
    fill(cnt, cnt + n, 0);
    for (int i = 1; i < n; i++) {
        p[i] = (i - 1) / k;
    }
    ll res = 0;
    for (int i = n - 1; i >= 0; i--) {
        cnt[i]++;
        if (i > 0) {
            cnt[p[i]] += cnt[i];
        }
        res += cnt[i];
    }
    return res;
}

void find(int k, ll s) {
    ll res = k;
    for (int i = 1; i <= n - k; i++) {
        res += i + k;
    }
    s = res - s;
    assert(s >= 0);
    set<pair<int, int>> q;
    for (int i = 1; i < n - k; i++) {
        g[i].insert(i + 1);
        p[i + 1] = i;
        h[i] = i;
    }
    h[n - k] = n - k;
    for (int i = n - k + 1; i <= n; i++) {
        h[i] = h[n - k] + 1;
        p[i] = n - k;
        g[n - k].insert(i);
    }
    for (int i = 1; i <= n; i++) {
        q.insert({h[i], i});
    }
    while (s > 0) {
        int v = q.rbegin()->second;
        int u;
        while (true) {
            u = q.begin()->second;
            assert((int) g[u].size() <= k);
            if ((int) g[u].size() == k) {
                q.erase({h[u], u});
                continue;
            }
            break;
        }

        int delta = h[v] - h[u] - 1;
        if (delta <= s) {
            g[p[v]].erase(v);
            q.erase({h[v], v});
            h[v] = h[u] + 1;
            p[v] = u;
            g[u].insert(v);
            s -= delta;
            q.insert({h[v], v});
        } else {
            q.erase({h[u], u});
        }
    }

    cout << "Yes\n";
    for (int i = 2; i <= n; i++) {
        cout << p[i] << " ";
    }
    cout << "\n";
}

void run() {
    ll s;
    cin >> n >> s;
    ll global_min = (n - 1) + (n - 1) + 1;
    ll global_max = 0;
    for (int i = 1; i <= n; i++) {
        global_max += i;
    }
    if (s < global_min || s > global_max) {
        cout << "No\n";
        return;
    }

    int left = 0;
    int right = n;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (get_minimal(mid) <= s) {
            right = mid;
        } else {
            left = mid;
        }
    }

    find(right, s);
}