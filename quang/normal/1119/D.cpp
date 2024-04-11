#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, q;
long long a[N];
long long val[N];

struct Query {
    long long l, r;
    int id;
} b[N];
long long res[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }    
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> b[i].l >> b[i].r;
        b[i].id = i;
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + q + 1, [](Query &u, Query &v) {
        return u.r - u.l < v.r - v.l;
    });
    long long sum = 0;
    int cnt = n - 1;
    for (int i = 1; i < n; i++) {
        val[i] = a[i + 1] - a[i] - 1;
        sum += val[i];
    }
    sort(val + 1, val + n);
    int cur = 1;
    for (int i = 1; i <= q; i++) {
        while (cur < n && val[cur] <= b[i].r - b[i].l) {
            cnt--;
            sum -= val[cur];
            cur++;
        }
        long long ans = a[n] - a[1] + 1 + b[i].r - b[i].l;
        ans += 1ll * (b[i].r - b[i].l) * cnt - sum;
        res[b[i].id] = ans;
    }
    for (int i = 1; i <= q; i++) {
        cout << res[i] << ' ';
    }
    cout << endl;
    return 0;
}