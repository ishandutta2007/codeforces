#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
 
typedef long long ll;

const ll inf = 1e18 + 65;

set<ll> used;
vector<ll> nums, squares;
ll n;

void make() {
    used.insert(1);
    for (ll i = 2; i * i * i < inf; ++i) {
        ll now = i * i * i;
        while (now < inf) {
            used.insert(now);
            if (log2(now) + log2(i) > log2(inf)) break;
            now *= i;
        }
    }
    n = used.size();
    for (auto i : used) nums.push_back(i);
    squares.resize(n);
    ll current = 0;
    for (ll i = 0; i < n; ++i) {
        if ((ll)(sqrt(nums[i])) * (ll)(sqrt(nums[i])) == nums[i]) ++current;
        squares[i] = current;
    }
}

ll get_ans(ll r) {
    if (r == 0) return 0;
    ll left = -1, right = n - 1;
    while (right - left > 1) {
        ll mid = left + right >> 1;
        if (nums[mid] > r) right = mid;
        else left = mid;
    }
    return (ll)((sqrt(r))) + left + 1 - squares[left];
}

void solve() {
    ll l, r;
    cin >> l >> r;
    cout << get_ans(r) - get_ans(l - 1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    make();
    ll q;
    cin >> q;
    for (ll i = 0; i < q; ++i) solve();
    return 0;
}