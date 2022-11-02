#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second
#define pb push_back

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
#include <chrono>
#include <complex>
#include <random>

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
    int r = 0;
    foru(i, 0, n)cin >> a[i], r += a[i];
    int l = 0, bst = r, mid;
    while (l <= r) {
        mid = (l + r + 1) / 2;
        int cnt = 0;
        vector<int> b;
        foru(i, 0, n) {
            if (a[i] == 1) {
                if (cnt < mid) {
                    cnt++;
                }
                else b.push_back(a[i]);
            }
            else b.push_back(a[i]);
        }
        int m = b.size();
        ford(i, m - 1, 0) {
            if (b[i] == 0) {
                if (cnt > 0) {
                    cnt--;
                    b[i] = 1;
                }
            }
        }
        bool bad = 0;
        foru(i, 0, m-1) {
            bad |= (b[i] > b[i + 1]);
        }
        if (!bad) {
            bst = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << bst << '\n';
}


int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}