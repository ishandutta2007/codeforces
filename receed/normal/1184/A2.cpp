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

const int N = 200002;
int a[N], n;
set<int> g;


void pr(int d) {
    vector<int> cnt(d);
    rep(i, n)
        cnt[i % d] ^= a[i];
    rep(i, d)
        if (cnt[i])
            return;
    g.insert(d);
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> n >> s;
    rep(i, n)
        a[i] = s[i] - '0';
    for (int i = 1; i * i <= n; i++)
        if (n % i == 0) {
            pr(i);
            if (i * i < n)
                pr(n / i);
        }
    int ans = 0;
    rep(i, n)
        if (g.count(__gcd(i, n)))
            ans++;
    cout << ans;
}