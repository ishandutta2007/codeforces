
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <set>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;



void solve() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    int cnt[2][2]{ {0,0},{0,0} };
    foru(i, 0, n) cnt[s[i] - '0'][t[i] - '0']++;
    int eq = cnt[0][0] + cnt[1][1], neq = cnt[1][0] + cnt[0][1];
    int bst = 1e9;
    //try eq
    if (eq & 1) {
        if (cnt[1][1] == cnt[0][0] || cnt[1][1] == cnt[0][0] + 1) {
            bst = min(bst, eq);
        }
    }
    //try neq
    if (neq % 2 == 0) {
        if (cnt[1][0] == cnt[0][1] || cnt[1][0] == cnt[0][1] + 1) {
            bst = min(bst, neq);
        }
    }
    if (bst > n) {
        cout << -1 << '\n';
    }
    else {
        cout << bst << '\n';
    }
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}