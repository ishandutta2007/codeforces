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

const int N = 1 << 21;
int a[N], n;
int lm[N], r1[N], r2[N];

void ck(int i, int x) {
    if (i > r1[x]) {
        r2[x] = r1[x];
        r1[x] = i;
    }
    else if (i > r2[x])
        r2[x] = i;
}

int q(int x) {
    for (int i = x; ; i = (i - 1) & x) {
        if (lm[i] < r2[x ^ i])
            return 1;
        if (i == 0)
            break;
    }
    return 0;
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    rep(i, N) {
        lm[i] = n;
        r1[i] = r2[i] = -1;
    }
    rep(i, n) {
        cin >> a[i];
        lm[a[i]] = min(lm[a[i]], i);
        ck(i, a[i]);
    }
    rep(i, 21)
        rep(j, N) {
            int k = j ^ (1 << i);
            if (k > j)
                continue;
            lm[k] = min(lm[k], lm[j]);
            ck(r1[j], k);
            ck(r2[j], k);
        }
    int ans = 0;
    for (int i = 20; i >= 0; i--)
        if (q(ans | (1 << i)))
            ans |= (1 << i);
    cout << ans;
}