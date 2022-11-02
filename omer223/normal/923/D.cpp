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

const int sz = 5e5;
int pre[2][sz];

int qu(int idx, int l, int r) {
    return pre[idx][r] - (l ? pre[idx][l - 1] : 0);
}

int main() {
    fast;
    string s, t;
    int q;
    cin >> s >> t >> q;
    int n = s.length(), m = t.length();
    vector<int> a, b;
    for (char& c : s) {
        if (c == 'A')a.push_back(0);
        else a.push_back(1);
        if (c == 'A')c = '0';
        else c = '1';
    }
    for (char& c : t) {
        if (c == 'A')b.push_back(0);
        else b.push_back(1);
        if (c == 'A')c = '0';
        else c = '1';
    }
    foru(i, 0, n)pre[0][i] = (i ? pre[0][i - 1] : 0) + a[i];
    foru(i, 0, m)pre[1][i] = (i ? pre[1][i - 1] : 0) + b[i];
    vector<int> lma(n, 1e9), lma2(m, 1e9);
    foru(i, 0, n) {
        if (s[i] == '0') {
            if (!i || lma[i - 1] == 1e9)lma[i] = i;
            else lma[i] = lma[i - 1];
        }
    }
    foru(i, 0, m) {
        if (t[i] == '0') {
            if (!i || lma2[i - 1] == 1e9)lma2[i] = i;
            else lma2[i] = lma2[i - 1];
        }
    }
    while (q--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2; l1--; r1--; l2--; r2--;
        int b1 = qu(0, l1, r1), b2 = qu(1, l2, r2);
        if ((abs(b1 - b2) & 1) || (b2 < b1)) {
            cout << "0";
        }
        else {
            int mlma = max(l1, lma[r1]);
            int mlma2 = max(l2, lma2[r2]);
            int c1 = max(0, (r1 - mlma + 1)), c2 = max(0, (r2 - mlma2 + 1));
            if (mlma == l1 && mlma2 != l2) {
                if (c1 > c2)cout << 1;
                else cout << 0;
            }
            else if (b1 == b2) {
                if (c1 >= c2 && ((c1 - c2) % 3 == 0))cout << 1;
                else cout << 0;
            }
            else {
                if (c1 >= c2)cout << 1;
                else cout << 0;
            }
        }

    }
    return 0;
}