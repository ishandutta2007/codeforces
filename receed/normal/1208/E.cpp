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

const int N = 1000001;
vector<pair<int, int>> q[N];
multiset<int> ss[N];

int ft(int p) {
    return ss[p].empty() ? 0 : *--ss[p].end();
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	ll n, w, l, x;
    cin >> n >> w;
    rep(i, n) {
        cin >> l;
        rep(j, l) {
            cin >> x;
            q[j].push_back({i+1, x});
            q[w - l + j + 1].push_back({-i-1, x});
        }
        if (l < w) {
            q[0].push_back({i+1, 0});
            q[w - l].push_back({-i-1, 0});
            q[l].push_back({i+1, 0});
        }
    }
    ll s = 0;
    rep(i, w) {
        for (auto &p : q[i]) {
            int v = abs(p.first) - 1;
            s -= ft(v);
            if (p.first > 0)
                ss[v].insert(p.second);
            else
                ss[v].erase(ss[v].find(p.second));
            s += ft(v);
        }
        cout << s << ' ';
    }
}