#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
#define int long long
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int n; cin >> n;
    int k = 0;
    vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; k += a[o]; }
    int an = 0;
    for (int i = 0; i < n; ++i) {
        an += a[i];
        if (an * 2 >= k) {
            an = i + 1;
            break;
        } 
    }
    cout << an;
}