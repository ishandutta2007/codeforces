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
	int n, pos;
    cin >> n;
    vector<int> a(n);
    set<int> s;
    rep(i, n)
        cin >> a[i];
    pos = n;
    while (pos > 0 && !s.count(a[pos - 1]))
        s.insert(a[--pos]);
    int ans = pos;
    rep(i, n) {
        while (pos < n && s.count(a[i]))
            s.erase(a[pos++]);
        if (s.count(a[i]))
            break;
        s.insert(a[i]);
        ans = min(ans, pos - i - 1);
    }
    cout << ans;
}