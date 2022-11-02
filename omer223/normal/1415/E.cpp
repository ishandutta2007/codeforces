
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;

const int sz = 6e5;
int n, k;
ll a[sz];

ll solve(vector<ll> v) {
    int m = v.size();
    sort(v.rbegin(), v.rend());
    if (m <= k + 1)return 0;
    else {
        ll tot = 0;
        int batches = k + 1;
        foru(i, 0, batches)v.pop_back();
        reverse(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            tot += (i / batches + 1) * v[i];
        }
        return tot;
    }
}

int main() {
    fast;
    cin >> n >> k;
    foru(i, 0, n)cin >> a[i];
    sort(a, a + n, greater<ll>());
    ll boss = 0, tot = 0;
    int i = 0;
    for (; i < n and boss >= 0; i++) {
        tot += boss;
        boss += a[i];
    }
    if (i == n)cout << tot << '\n';
    else {
        vector<ll> v{boss};
        for (; i < n; i++)v.pb(a[i]);
        tot += solve(v);
        cout << tot << '\n';
    }
    return 0;
}