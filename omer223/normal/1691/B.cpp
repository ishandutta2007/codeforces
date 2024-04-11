#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <numeric>
#include <iomanip>
#include <string>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ld, ld> pld;


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    foru(i, 0, n)cin >> a[i];
    vector<int> p(n, -1);
    int prv = a[0], st=0;
    bool bad = 0;
    foru(i, 1, n) {
        if (prv != a[i]) {
            int len = i - st;
            if (len == 1) {
                bad = 1;
                break;
            }
            foru(j, st, i - 1) {
                p[j] = j + 1;
            }
            p[i - 1] = st;
            st = i;
        }
        prv = a[i];
    }
    int i = n;
    int len = i - st;
    if (len == 1) {
        bad = 1;
    }
    foru(j, st, i - 1) {
        p[j] = j + 1;
    }
    p[i - 1] = st;
    if (bad) {
        cout << -1 << '\n';
        return;
    }
    foru(i, 0, n)cout << p[i] + 1 << ' ';
    cout << '\n';
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}