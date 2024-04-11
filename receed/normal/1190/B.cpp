#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ld = long double;

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	ll n;
    cin >> n;
    ll s = -n * (n - 1) / 2, x;
    set<int> cnt;
    int f = -1;
    rep(i, n) {
        cin >> x;
        s += x;
        if (cnt.count(x)) {
            if (f > -1) {
                cout << "cslnb";
                return 0;
            }
            f = x;
        }
        cnt.insert(x);
    }
    if (f > -1)
        if (f == 0 || cnt.count(f - 1)) {
            cout << "cslnb";
            return 0;
        }
    if (s % 2)
        cout << "sjfnb";
    else
        cout << "cslnb";

}