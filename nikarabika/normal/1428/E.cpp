//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 1e5 + 100;
LL a[maxn];
LL cnt[maxn];
set<pll> s;
int n, k;

LL func(LL x, LL t) {
    LL r = x % t;
    LL q = x / t;
    return r * (q + 1) * (q + 1) + (t - r) * q * q;
}

LL delta(LL x, LL t) {
    return func(x, t + 1) - func(x, t);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    cin >> n >> k;
    k -= n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[i] = 1;
    }
    for (int i = 0; i < n; i++) 
        s.insert(MP(delta(a[i], cnt[i]), i));
    while (k) {
        int id = s.begin()->R;
        s.erase(s.begin());
        cnt[id]++;
        s.insert(MP(delta(a[id], cnt[id]), id));
        k--;
    }
    LL ans = 0;
    for (int i = 0; i < n; i++)
        ans += func(a[i], cnt[i]);
    cout << ans << endl;
	return 0;
}