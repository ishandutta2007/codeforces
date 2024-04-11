#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <bitset>
#include <iomanip>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
using namespace std;

const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 100001;
ll md = 1000000007;

void solve() {
    string s; cin >> s;
    map<pair<int, int>, ll> mp;
    vector<ll> co(26, 0);
    for(auto c: s) {
        int a = c - 'a';
        range(i, 26) {
            mp[{i, a}] += co[i];
        }
        co[a]++;
    }
    ll f = 0;
    for(auto p: mp) f = max(f, p.second);
    range(i, 26) f = max(f, co[i]);
    cout << f;
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