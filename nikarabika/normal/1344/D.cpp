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

inline LL diff(LL x, LL y) {
    if (x == y) return 0;
    return -x + (3 * y * y + 3 * y + 1);
}

LL get(LL x, LL d) {
    LL lo = -1,
       hi = x;
    while (hi - lo > 1) {
        LL mid = (lo + hi) >> 1;
        if (diff(x, mid) <= d)
            lo = mid;
        else
            hi = mid;
    }
    return hi;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    LL n, k;
    cin >> n >> k;
    LL a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    LL hi = 4e18,
        lo = -4e18;
    while (hi - lo > 1) {
        LL mid = (lo >> 1) + (hi >> 1) + ((lo & hi) & 1);
        LL cnt = 0;
        for (int i = 0; i < n; i++)
            cnt += get(a[i], mid);
        if (cnt >= k)
            hi = mid;
        else
            lo = mid;
    }
    LL sumb = 0;
    LL b[n];
    for (int i = 0; i < n; i++)
        sumb += b[i] = get(a[i], lo);
    LL need = k - sumb;
    for (int i = 0; i < n; i++)
        if (need and get(a[i], hi) > b[i])
            b[i]++, need--;
    for (int i = 0; i < n; i++)
        cout << b[i] << ' ';
    cout << '\n';
	return 0;
}