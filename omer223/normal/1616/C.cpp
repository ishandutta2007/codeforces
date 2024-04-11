
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

const int sz = 1e2;
int n;
int a[sz];
const int D = 205;

void solve() {
    cin >> n;
    foru(i, 0, n)cin >> a[i];
    if (n <= 2) {
        cout << 0 << '\n';
        return;
    }
    int bst = n;
    foru(i, 0, n) {
        foru(j, i + 1, n) {
            int cnt = 0;
            foru(k, 0, n) {
                if (k == i || k == j)continue;
                else {
                    int d1 = (a[i] - a[k]) * (i - j), d2 = (a[i] - a[j]) * (i - k);
                    if (d1 != d2)cnt++;
                }
            }
            bst = min(bst, cnt);
        }
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