#include <bits/stdc++.h>

using namespace std;

const int N = 5e6;

int m, a, b;
bitset<N + 1> used;
long long res = 0;
int sz;
set<int> nxt;

int go(int u, int base) {
    // cout << u << ' ' << base << endl;
    used[u] = 1;
    res += m + 1 - base;
    int ans = 1e9;
    if (u >= b && used[u - b] == 0) {
        int foo = go(u - b, base);
        ans = min(ans, foo);
    }
    if (u + a <= base && used[u + a] == 0) {
        int foo = go(u + a, base);
        ans = min(ans, foo);
    }
    if (u + a > base) {
        ans = min(ans, u + a);
        nxt.insert(u + a);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> a >> b;
    int cur = 0;
    sz = min(m, N);
    while (1) {
        go(cur, cur);
        if (nxt.size() == 0) break;
        int id = *nxt.begin();
        nxt.erase(nxt.begin());
        if (id > sz) break;
        cur = id;
    }
    int cnt = 0;
    if (m > N) {
        int foo = __gcd(a, b);
        int num = (m - cur) / foo;
        res += 1ll * (m + 1) * num;
        long long now = 1ll * num * cur;
        long long bar = 1ll * num * (num + 1) / 2;
        now += 1ll * foo * bar;
        res -= now;
    }   
    cout << res << endl;
    return 0;
}