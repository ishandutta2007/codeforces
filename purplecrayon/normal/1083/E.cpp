#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct Rect {
    ll x, y, a;
    bool operator<(Rect B) { return x < B.x; }
};

Rect a[1000001];
ll dp[1000001];

double slope(int i, int j) { return (double)(dp[i] - dp[j]) / (a[i].x - a[j].x); }

int main() {
    iostream::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].a;
    }
    sort(a + 1, a + n + 1);

    deque<ll> q;
    q.push_back(0);
    for (int i = 1; i <= n; i++) {
        while (q.size() > 1 && slope(q[0], q[1]) >= a[i].y) q.pop_front();

        ll j = q.front();
        dp[i] = max(dp[i - 1], a[i].x * a[i].y - a[i].a + dp[j] - a[j].x * a[i].y);

        while (q.size() > 1 && slope(q[q.size() - 2], q.back()) <= slope(q.back(), i)) q.pop_back();
        q.push_back(i);
    }

    cout << dp[n];
    return 0;
}