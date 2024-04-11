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

#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
using namespace std;

ll get_ans(vector<ll> &s2) {
    ll ans = 1;
    ll prev = 0;
    for(ll j = (ll)s2.size() - 1; j >= 0; --j) {
        ans *= j + 2 - s2[j] - (s2[j] == 0);
        if (prev && s2[j] == s2[j + 1]) {
            prev++;
        } else {
            prev = 1;
        }
        ans /= prev;
    }
    return ans;
}

void solve() {
    ll k; cin >> k;
    ll i = 2;
    vector<ll> s2;
    while(k) {
        s2.push_back(k % i);
        k /= i;
        i++;
    }
    sort(all(s2));
    ll ans = get_ans(s2);
    if (s2[0] == 0) {
        reverse(all(s2));
        s2.pop_back();
        reverse(all(s2));
        ans -= get_ans(s2);
    }
    cout << ans - 1 << '\n';
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int tests; cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}