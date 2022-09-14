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

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	ll n;
    string s;
    cin >> n >> s;
    ll ans = n * (n - 1) / 2, cc = 0, cl = 1, cr = 1;
    rep(i, n - 1)
        if (s[i] != s[i + 1])
            cc++;
    while (cl < n && s[cl] == s[cl - 1])
        cl++;
    while (cr < n && s[n - cr] == s[n - cr - 1])
        cr++;
    cout << ans - n * 2 + cl + cr + cc;
}