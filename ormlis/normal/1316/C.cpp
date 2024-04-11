#include <iostream>
#include <random>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <queue>
#include <cmath>
#include <chrono>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 1001;
ll md = 1000000007;

//double getTime() { return clock() / (double) CLOCKS_PER_SEC;};

vector<int> a, b;
int n, m, p;

void solve() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    cin >> n >> m >> p;
    a.resize(n);
    b.resize(m);
    range(i, n) cin >> a[i];
    range(i, m) cin >> b[i];
    int t = 0;
    range(i, n) {
        if (a[i] % p) {
            t += i;
            break;
        }
    }
    range(i, m) {
        if (b[i] % p) {
            t += i;
            break;
        }
    }
    cout << t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests=1;
    range(_, tests) {
        solve();
    }
    return 0;
}