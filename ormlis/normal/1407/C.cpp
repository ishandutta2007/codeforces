#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <map>
#include <unordered_set>
#include <tuple>
#include <queue>
#include <set>
#include <cstring>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 2e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

int get(int x, int y) {
    cout << "? " << x << " " << y << endl;
    int k; cin >> k;
    if (k == -1) exit(0);
    return k;
}

void solve() {
    int n; cin >> n;
    int j = 0;
    vector<int> a(n);
    vector<int> u(n, 0);
    for(int i = 1; i < n; ++i) {
        int k = get(i + 1, j + 1);
        int w = get(j + 1, i + 1);
        if (k > w) {
            a[i] = k;
            u[k-1] = 1;
         } else {
            a[j] = w;
            j = i;
            u[w-1] = 1;
        }
    }
    cout << "! ";
    range(i, n) if (!u[i]) a[j] = i + 1;
    range(i, n) cout << a[i] << " ";
    cout << endl;
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    //cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}