#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("Ofast", "-funroll-loops", "-fdelete-null-poller-checks")
#pragma GCC target("ssse3", "sse3", "sse2", "sse", "avx2", "avx")
#pragma GCC optimize(3, "Ofast", "inline")
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second
#define pb push_back
#define CW 1
#define CCW 2
#define COLIN 3

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
#include <cmath>
#include <math.h>
#include <iomanip>
#include <numeric>
#include <random>
#include <time.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    if (a + b > n - 2 || abs(a - b) > 1) {
        cout << -1 << '\n';
        return;
    }
    vector<int> v;
    int ca = a, cb = b;
    if (a <= b) {
        v.push_back(n);
        while (v.size() != n) {
            if (ca && cb) {
                int bk = v.back();
                v.push_back(n - bk + 1);
                v.push_back(bk - 1);
                ca--;
                cb--;
            }
            else if (cb) { //change
                int bk = v.back();
                int st = n - bk + 1;
                while (v.size() != n) {
                    v.push_back(st);
                    st++;
                }
                cb--;
                break;
            }
            else {
                int st = v.back() - 1;
                while (v.size() != n) {
                    v.push_back(st);
                    st--;
                }
                break;
            }
        }
    }
    else {
        v.push_back(1);
        while (v.size() != n) {
            if (ca && cb) {
                int bk = v.back();
                v.push_back(n - bk + 1);
                v.push_back(bk + 1);
                ca--;
                cb--;
            }
            else if (ca) { //change
                int bk = v.back();
                int st = n - bk + 1;
                while (v.size() != n) {
                    v.push_back(st);
                    st--;
                }
                ca--;
                break;
            }
            else {
                int st = v.back() + 1;
                while (v.size() != n) {
                    v.push_back(st);
                    st++;
                }
                break;
            }
        }
    }
    if (ca != 0 || cb != 0 || v.size() != n) {
        cout << -1 << '\n';
        return;
    }
    for (int x : v)cout << x << ' ';
    cout << '\n';
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}