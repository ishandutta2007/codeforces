#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const ll INF = 1e18;
const int MAXN = (int) 1e6;

struct Data {
    ll x, y;
    ll a;
    bool operator <(const Data &other) const {
        return x < other.x;
    }
}arr[MAXN + 1];

ll dp[MAXN + 1];

struct Line {
    ll a, b;
};

Line stk[MAXN + 1];
int sz;

inline double inter(Line l1, Line l2) {
    if(l1.a == l2.a)
        return 1.0 * INF;
    return 1.0 * (l2.b - l1.b) / (l1.a - l2.a);
}

inline void add(Line l) {
    while(sz > 1 && inter(stk[sz - 1], l) - inter(stk[sz - 1], stk[sz]) < 0) {
        sz--;
    }
    stk[++sz] = l;
}

inline ll get(Line l, ll x) {
    return l.a * x + l.b;
}

inline ll query(ll x) {
    int res = -1;
    for(int step = 1 << 19; step; step >>= 1) {
        if(res + step < sz && get(stk[res + step], x) <= get(stk[res + step + 1], x))
            res += step;
    }
    res++;
    if(res > sz) {
        return -INF;
    }
    return get(stk[res], x);
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> arr[i].x >> arr[i].y >> arr[i].a;
    }
    sort(arr + 1, arr + n + 1);
    ll ans = 0;
    for(i = 1; i <= n; i++) {
        dp[i] = max(query(-arr[i].y), 0LL) + 1LL * arr[i].x * arr[i].y - arr[i].a;
        add({arr[i].x, dp[i]});
        ans = max(ans, dp[i]);
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}