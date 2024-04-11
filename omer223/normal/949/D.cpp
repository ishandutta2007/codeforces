#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second
#define chkmin(a, b) (a = ((a > b) ? b : a))
#define chkmax(a, b) (a = ((a < b) ? b : a))

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>
#include <set>
#include <map>
#include <random>


using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ld, ld> pld;
typedef pair<ll, int> pdi;


const int sz = 1e5 + 5;
ll n, d, b;
ll a[sz];

bool can(int thres, int r, vector<ll> c) {
    int prv = -1, ptr, stacks = 0, avail = 0;
    foru(i, 0, r) {
        ptr = min(n - 1, i + d * (i + 1));
        foru(j, prv + 1, ptr + 1) {
            avail += c[j];
        }
        if (avail >= b) {
            avail -= b;
            stacks++;
        }
        prv = ptr;
    }
    return stacks >= thres;
}

bool ok(int thres) {
    vector<ll> c(n);
    int reqstk = (n + 1) / 2 - thres;
    ll tot = 0, up = b * reqstk;
    foru(i, 0, n) {
        int q = min(up - tot, a[i]);
        tot += q;
        c[i] = q;
        if (tot == up)break;
    }
    if (!can(reqstk, (n + 1) / 2, c))return 0;
    foru(i, 0, n)c[i] = 0;
    tot = 0;
    reqstk = n / 2 - thres;
    up = b * reqstk;
    ford(i, n - 1, 0) {
        int q = min(up - tot, a[i]);
        tot += q;
        c[i] = q;
        if (tot == up)break;
    }
    reverse(c.begin(), c.end());
    if (!can(reqstk, n / 2, c))return 0;
    return 1;
}

int main() {
    fast;
    cin >> n >> d >> b;
    foru(i, 0, n)cin >> a[i];
    int l = 0, r = (n - 1) / 2, mid, bst = (n + 1) / 2;
    while (l <= r) {
        mid = (l + r + 1) / 2;
        if (ok(mid)) {
            bst = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << bst << '\n';
    return 0;
}