#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 100010;
const long long INF = 1e18;

int n, k;
int a[N];

struct Data {
    int maxVal, num, val;

    bool operator < (const Data &o) const {
        if (maxVal != o.maxVal) return maxVal > o.maxVal;
        if (val != o.val) return val > o.val;
        return num < o.num;
    }
};

long long get(int val, int num) {
    if (val < num) return INF;
    int d = val / num;
    int r = val % num;
    return num * d * d + r * (2 * (d + 1) - 1);
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    int cur = n;
    long long res = 0;
    multiset<Data> s;
    for (int i = 1; i <= n; i++) {
        int u;
        cin >> u;
        res += u * u;
        s.insert({get(u, 1) - get(u, 2), 1, u});
    }
    while (cur < k) {
        auto now = *s.begin();
        s.erase(s.begin());
        res -= now.maxVal;
        cur++;
        now.num++;
        now.maxVal = get(now.val, now.num) - get(now.val, now.num + 1);
        s.insert(now);
    }
    cout << res << endl;
    return 0;
}