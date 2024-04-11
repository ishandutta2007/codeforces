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

const int sz = 1e2 + 5;
ll part[sz];

void prec() {
    part[0] = 1;
    foru(i, 2, sz) {
        foru(j, 1, i + 1)part[i] += part[i - j];
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    foru(i, 0, n)cin >> a[i];
    ll tot = 0;
    foru(i, 0, n) {
        foru(j, i, n) {
            ll cnt = 0;
            foru(k, i, j + 1) {
                if (a[k] == 0)cnt += 2;
                else cnt++;
            }
            tot += cnt;
        }
    }
    cout << tot << '\n';
}

int main() {
    fast;
    prec();
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}