#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>
#include <fstream>
#include <cstring>

#define ll long long
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()
using namespace std;
ll MOD = 1e9 + 7;
ll sub(ll a, ll b) {
    if (a - b < 0) return a - b + MOD;
    return a - b;
}

ll add(ll a, ll b) {
    if (a + b >= MOD) return a + b - MOD;
    return a + b;
}

ll mul(ll a, ll b) {
    return a * b % MOD;
}


void solve() {
    string s;
    int x; cin >> x;
    cin >> s;
    vector<int> a((int)s.size());
    range(i, (int)s.size()) {
        a[i] = (int) s[i] - '1';
    }
    ll e = (ll)s.size();
    int flag = 1;
    range(i, x) {
        int w = a[i];
        if (e >= x) flag = 0;
        if(flag) {
            range(j, w) {
                for(int f = i + 1; f <= e - 1; ++f) {
                    a.push_back(a[f]);
                }
            }
        }
        e = add(e, mul(sub(e, i + 1), w));
    }
    cout << e << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tests;
    cin >> tests;
    range(i, tests) {
        solve();
    }
    return 0;
}