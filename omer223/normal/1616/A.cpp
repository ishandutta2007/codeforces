
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
#include <map>
#include <queue>
#include <math.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> abscnt(101);
    foru(i, 0, n)cin >> a[i], abscnt[abs(a[i])]++;
    int tot = (abscnt[0] != 0);
    foru(i, 1, 101) {
        int x = abscnt[i];
        if (x == 1)tot++;
        else if (x >= 2)tot += 2;
    }
    cout << tot << '\n';
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}