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
const int maxN = 1e6 + 1;
ll md = 1000000007;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int k; cin >> k;
    map<int, int> mp;
    vector<bool> d(1e7+1, true);
    vector<int> sf(1e7+1, 0);
    vector<int> a(k);
    range(i, k) cin >> a[i];
    range(i, k) sf[a[i]]++;
    for(int i = 1e7-1; i>= 0; --i) {
        sf[i] += sf[i+1];
    }

    auto get = [] (ll num, ll pr) {
        ll res = 0;
        while(num) {
            num /= pr;
            res += num;
        }
        return res;
    };
    auto binsearch = [&get] (ll pr, ll sum) {
        ll l = -1, r = pr * sum;
        while(r - l > 1) {
            ll mid = (r + l) / 2;
            if (get(mid, pr) >= sum) r = mid;
            else l = mid;
        }
        return r;
    };
    ll mx = 1;
    for(int i = 2; i <= 1e7; ++i) {
        if (d[i]) {
            ll w = 0;
            for(int j = i; j <= 1e7; j+=i) {
                int e = j;
                while(e % i == 0) {
                    e /= i;
                    w += sf[j];
                }
                d[j] = false;
            }
            mx = max(mx, binsearch(i, w));
        }
    }
    cout << mx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}