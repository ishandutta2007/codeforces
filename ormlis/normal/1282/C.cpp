#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_map>
#include <fstream>
#include <cstring>
#include <map>
#include <bitset>
#include <iomanip>

#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
using namespace std;

const int Nm=200001;

int types[Nm];

void solve() {
    ll n, T, a, b; cin >> n >> T >> a >> b;
    vector<pair<pair<int, int>, int>> times;
    times.push_back({{T, 1}, -1});
    ll s = 0;
    range(i, n) {
        cin >> types[i];
        s += types[i];
    }
    ll p = n - s;
    range(i, n) {
        ll t; cin >> t;
        times.push_back({{t, 0}, i});
        if (t) {
            times.push_back({{t - 1, 1}, i});
        }
    }
    sort(all(times));
    ll cur = 0;
    int zad = 0;
    int ans = 0;
    for(auto pa: times) {
        ll t = pa.first.first;
        int typ = pa.first.second;
        int i = pa.second;
        if (typ) {
            ll ost = t - cur;
            if (ost < 0) continue;
            int ehse = min(p, ost / a);
            ost -= ehse * a;
            int ans_cur = zad + ehse;
            ehse = min(s, ost / b);
            ost -= ehse * b;
            ans_cur += ehse;
            ans = max(ans, ans_cur);
        } else {
            if (types[i]) {
                cur += b;
                s--;
            } else {
                cur += a;
                p--;
            }
            zad++;
        }
    }
    cout << ans << '\n';
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int tests; cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}