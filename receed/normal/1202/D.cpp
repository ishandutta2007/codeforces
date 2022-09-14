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
	int t, n;
    cin >> t;
    rep(z, t) {
        cin >> n;
        vector<int> p;
        for (ll i = 50000; i >= 2; i--) {
            ll c = i * (i - 1) / 2;
            while (n >= c) {
                p.push_back(i);
                n -= c;
            }
        }
        reverse(all(p));
        string s = "1";
        int f = 0;
        for (int i : p) {
            while (f < i) {
                s.push_back('3');
                f++;
            }
            s.push_back('7');
        }
        cout << s << '\n';
    }
}