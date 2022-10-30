#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("Ofast", "-funroll-loops", "-fdelete-null-pointer-checks")
#pragma GCC target("ssse3", "sse3", "sse2", "sse", "avx2", "avx")
#pragma GCC optimize(3, "Ofast", "inline")
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (ll i = k; i < n; i++)
#define ford(i, k, n) for (ll i = k; i >= n; i--)
#define ff first
#define ss second
#define pb push_back

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <bitset>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <map>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;


const int sz = 7e5;
int n, k;
string s, t;
int nxts[sz], nxtt[sz];

ll calcFull(ll h) {
    if (h >= 40)return 1e15;
    return (1LL << h) - 1;
}

ll leafAmt(ll h) {
    if (h >= 40)return 1e15;
    return (1LL << (h - 1));
}

ll getBest(ll h, ll k) {
    if (k == 1)return h;
    ll tot = 1, curleaf = 1;
    k--;
    h--;
    while (curleaf < k && h > 0) {
        h--;
        if (2 * curleaf < k) {
            tot += (2 * curleaf);
            curleaf <<= 1;
        }
        else {
            tot += k;
            curleaf = k;
            break;
        }
    }
    tot += curleaf * h;
    return tot;
}

int main() {
    fast;
    cin >> n >> k >> s >> t;
    ll tot = 0;
    int i = 0;
    for (i; i < n; i++) {
        if (s[i] != t[i])break;
    }
    if (i == n || k == 1) {
        cout << n << '\n';
        return 0;
    }
    tot += i;
    s = s.substr(i, n - i);
    t = t.substr(i, n - i);
    n = s.length();
    int si = 1, ti = 1;
    ll ssons = 1, tsons = 1, sp = 0, tp = 0;
    tot += 2;
    while (si < n && ssons + tsons < k) {
        ll toadd = min(sp, k - ssons - tsons);
        sp += toadd;
        ssons += toadd;
        toadd = min(tp, k - ssons - tsons);
        tp += toadd;
        tsons += toadd;
        if (ssons + tsons < k) {
            if (s[si] == 'a') {
                ssons++;
                sp++;
            }
            if (ssons + tsons < k) {
                if (t[ti] == 'b') {
                    tsons++;
                    tp++;
                }
            }
        }
        tot += (ssons + tsons);
        si++;
        ti++;
    }
    tot += (ssons + tsons) * (n - si);
    cout << tot << '\n';
    return 0;
}