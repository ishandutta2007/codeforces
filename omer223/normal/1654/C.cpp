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
#include <string>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;
typedef pair<ld, ld> pld;

void solve() {
    int n;
    cin >> n;
    ll sm = 0;
    vector<int> a(n);
    foru(i, 0, n)cin >> a[i], sm += a[i];
    multiset<ll,greater<ll>> as, bs;
    foru(i, 0, n)as.insert(a[i]);
    bs.insert(sm);
    int opers = 0;
    bool bad = 0;
    while (opers < n - 1) {
        if (bs.empty()) {
            bad = 1;
            break;
        }
        auto ii = *bs.begin();
        ll x = ii;
        if (as.find(x) != as.end()) {
            bs.erase(bs.find(x));
            as.erase(as.find(x));
        }
        else {
            bs.erase(bs.find(x));
            bs.insert(x / 2);
            bs.insert((x + 1) / 2);
            opers++;
        }
    }
    while (!bs.empty()) {
        auto ii = *bs.begin();
        ll x = ii;
        if (as.find(x) != as.end()) {
            bs.erase(bs.find(x));
            as.erase(as.find(x));
        }
        else break;
    }
    if (opers < n - 1 || !bs.empty())cout << "NO\n";
    else cout << "YES\n";
}



int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}