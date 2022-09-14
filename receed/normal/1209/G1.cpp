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
 
const int N = 200001;
int a[N], l[N], r[N], ps[N], cnt[N];
 
int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n, q;
    cin >> n >> q;
    rep(i, N) {
        l[i] = n;
        r[i] = -1;
    }
    rep(i, n) {
        cin >> a[i];
        l[a[i]] = min(l[a[i]], i);
        r[a[i]] = max(r[a[i]], i);
        cnt[a[i]]++;
    }
    rep(i, N)
        if (r[i] != -1) {
            ps[l[i]]++;
            ps[r[i]]--;
        }
    int lx = 0, ans = 0, cs = 0;
    rep(i, n) {
        cs += ps[i];
        if (cs != 0)
            continue;
        int mx = 0;
        for (int j = lx; j <= i; j++)
            mx = max(mx, cnt[a[j]]);
        lx = i + 1;
        ans += mx;
    }
    cout << n - ans;
}