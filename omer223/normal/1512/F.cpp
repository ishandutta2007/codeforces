#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;

ll myceil(ll a, ll b) {
    return a / b + (a % b != 0);
}

void solve() {
    ll n, c;
    cin >> n >> c;
    vector<int> a(n), b(n - 1);
    foru(i, 0, n)cin >> a[i];
    foru(i, 0, n - 1)cin >> b[i];
    ll bst = 1e18, moneys = 0, days = 0;
    foru(i, 0, n) {
        if (c <= moneys) {
            bst = min(bst, days);
        }
        else {
            bst = min(bst, days + myceil(c - moneys, a[i]));
        }
        if (i == n - 1)break;
        if (moneys >= b[i]) {
            moneys -= b[i];
        }
        else {
            ll q = myceil(b[i] - moneys, a[i]);
            moneys += q * a[i];
            days += q;
            moneys -= b[i];
        }
        days++;
    }
    cout << bst << '\n';
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}