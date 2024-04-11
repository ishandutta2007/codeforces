#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double ld;

void setmax(int &x, int y){
    x = max(x, y);
}

void setmax(ll &x, ll y){
    x = max(x, y);
}

const int maxn = 1e5 + 100, inf = 1e9 + 100;

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll l1, r1, t1, l2, r2, t2;
    cin >> l1 >> r1 >> t1 >> l2 >> r2 >> t2;
    if (t1 < t2){
        swap(l1, l2);
        swap(r1, r2);
        swap(t1, t2);
    }
    r1 -= l1;
    l2 -= l1;
    r2 -= l1;
    l1 = 0;
    if (l2 < 0){
        ll o = (-l2 + t2 - 1) / t2;
        l2 += o * t2;
        r2 += o * t2;
    }
    ll len1 = r1 - l1 + 1;
    ll len = r2 - l2 + 1;
    ll g = __gcd(t1, t2);
    ll o = (t1 - 1 - l2) / g;
    ll ans = 0;
    setmax(ans, min(len1, len - (t1 - l2 - o * g)));
    o++;
    l2 = (l2 + o * g) % t1;
    if (l2 <= r1)
        setmax(ans, min(len, r1 - l2 + 1));
    cout << ans;
}