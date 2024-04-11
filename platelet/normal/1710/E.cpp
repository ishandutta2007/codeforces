#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
using namespace std;
using ll = long long;

const int N = 2e5 + 8;

int n, m, a[N], b[N];
ll c[N], d[N];

ll calc0(int lim) {
    int j = m;
    mem(c, 0), mem(d, 0);
    ll sum = 0;
    rep(i, 1, n) {
        while(j && a[i] + b[j] > lim) j--;
        if(j * 2 >= m) d[j]++, d[m - j]--, sum += m - j;
        else c[j + 1]++, c[m - j + 1]--, sum += j;
    }
    rep(i, 1, m) c[i] += c[i - 1];
    rep(i, 1, m) c[i] += c[i - 1];
    per(i, m, 1) d[i] += d[i + 1];
    per(i, m, 1) d[i] += d[i + 1];
    ll mn = INT64_MAX;
    rep(i, 1, m) mn = min(mn, c[i - 1] + d[i]);
    return sum + mn;
}
ll calc1(int lim, int x, int y) {
    int j = m;
    mem(c, 0), mem(d, 0);
    ll sum = 0;
    rep(i, 1, n) {
        while(j && a[i] + b[j] > lim) j--;
        if(i == x) {
            if(j * 2 >= m) d[j]++, d[m - j - 1]--, sum += m - j - 1;
            else {
                sum += j;
                if(y >= m - j) c[j + 1]++, c[m - j]--;
                else c[j + 1]++, c[m - j + 1]--, c[y]--, c[y + 1]++;
            }
        } else {
            if(j * 2 >= m) d[j]++, d[m - j]--, sum += m - j;
            else c[j + 1]++, c[m - j + 1]--, sum += j;
        }
    }
    rep(i, 1, m) c[i] += c[i - 1];
    rep(i, 1, m) c[i] += c[i - 1];
    per(i, m, 1) d[i] += d[i + 1];
    per(i, m, 1) d[i] += d[i + 1];
    ll mn = INT64_MAX;
    rep(i, 0, m) mn = min(mn, c[i] + d[i + 1]);
    return sum + mn;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, m) cin >> b[i];
    int a1 = a[1], b1 = b[1];
    int l = 2, r = a1 + b1 - 1;
    sort(a + 1, a + n + 1), a1 = lower_bound(a + 1, a + n + 1, a1) - a;
    sort(b + 1, b + m + 1), b1 = lower_bound(b + 1, b + m + 1, b1) - b;
    while(l <= r) {
        int mid = l + r >> 1;
        calc0(mid) != calc1(mid, a1, b1) ? r = mid - 1 : l = mid + 1;
    }
    cout << l;
}