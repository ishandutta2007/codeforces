#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>
#include <fstream>
#include <cstring>
#include <map>

#define ll long long
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

using namespace std;

int arr[201];

void solve(ll n, ll k) {
    if (n == k) {cout << 1; return;}
    if (n == k + 1) {cout << 2; return;}
    ll k1 = 1;
    ll pos1 = 1, pos2 = 2 - (n % 2 == 0);
    while (k1 * 2 < k) {
        ll m = n;
        n /= 2;
        if (n % 2 == 0) {
            if (m % 2 == 0) {
                pos1 = pos1 + k1 + 1;
            } else {
                pos1 = pos2 + k1 + 1;
            }
            pos2 = 1 + k1 * 2;
        } else {
            if (m % 2 == 0) {
                pos1 = pos1 + 1;
            } else {
                pos1 = pos2 + 1;
            }
            pos2 = pos1 + k1 * 2 + 1;
        }
        k1 *= 2;
        k1++;
    }
    if (pos1 >= k) {
        cout << n;
    } else if (pos2 >= k || n == 2) {
        cout << n - 1;
    }
    else if (n % 2 == 0 || k1 >= k || n == 3) {
        cout << n - 2;
    } else {
        cout << n - 3;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(i, tests) {
        ll n, k; cin >> n >> k;
        solve(n, k);
    }
    return 0;
}