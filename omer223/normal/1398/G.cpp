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
#include <memory>
#include <numeric>
#include <complex>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ld, ld> pld;
typedef pair<ll, int> pdi;

const int sz = 2e5 + 1, mxn = 1e6 + 1;
bitset<sz> tot, now;
int n, x, y;
int a[sz + 5], b[sz + 5];
vector<int> divs[mxn];
int ret[mxn];

void comp() {
    now[0] = 1;
    foru(i, 0, n) {
        now <<= b[i];
        tot |= now;
        now[0] = 1;
    }
}

void getdivs() {
    for (int i = 1; i < mxn; i++) {
        for (int j = i; j < mxn; j += i)divs[j].push_back(i);
    }
}

int main() {
    //fast;
    getdivs();
    scanf("%d %d %d", &n, &x, &y);
    int ty = 2 * y;
    foru(i, 0, n + 1)scanf("%d", &a[i]);
    foru(i, 0, n)b[i] = a[i + 1] - a[i];
    comp();
    int q;
    scanf("%d", &q);
    while (q--) {
        int l;
        scanf("%d", &l);
        if (ret[l])printf("%d\n", ret[l]);
        else {
            int bst = -1;
            for (int d : divs[l]) {
                int del = d - ty;
                if (del > 0 && (!(del & 1))) {
                    int d2 = (del >> 1);
                    if (d2 <= x && tot[d2])chkmax(bst, d);
                }
            }
            printf("%d\n", bst);
        }
    }
    return 0;
}