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
using ul = unsigned long long;
using ld = long double;

const int N = 63;
vector<ll> a[N];

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	ll n, x, y, c;
    cin >> n;
    rep(i, n) {
        cin >> x;
        y = x;
        c = 0;
        while (x % 2 == 0) {
            c++;
            x /= 2;
        }
        a[c].push_back(y);
    }
    int mp = 0;
    rep(i, N)
        if (a[i].size() > a[mp].size())
            mp = i;
    cout << n - a[mp].size() << '\n';
    rep(i, N)
        if (i != mp)
            for (ll j : a[i])
                cout << j << ' ';
}