#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 4e18;
const int INFi = 2e9;
const int maxN = 2e5 + 1;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    int l = 0, r = n - 1;
    int a1 = 0, b1 = 0;
    int preva1 = 0, prevb1 = 0;
    int i = 0;
    while(r - l >= 0) {
        if (i % 2 == 0) {
            preva1 = a1;
            while(r - l >= 0 && a1 - preva1 <= prevb1) {
                a1 += a[l];
                l++;
            }
            preva1 = a1 - preva1;
        } else {
            prevb1 = b1;
            while(r - l >= 0 && b1 - prevb1 <= preva1) {
                b1 += a[r];
                r--;
            }
            prevb1 = b1 - prevb1;
        }
        i++;
    }
    cout << i << " " << a1 << " " << b1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}