#pragma GCC optimize("O3")
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cassert>
#include <queue>
#include <deque>
 
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
 
using namespace std; using ll = long long; using pii = pair<int, int>; using vi = vector<int>; using ld = long double;

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n;
    cin >> n;
    ll div = 1;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            div = i;
            break;
        }
    }
    if (div == 1) {
        div = n;
    }
    while (n > 1 && n % div == 0) {
        n /= div;
    }
    if (n > 1) {
        cout << 1;
    } else {
        cout << div;
    }
}