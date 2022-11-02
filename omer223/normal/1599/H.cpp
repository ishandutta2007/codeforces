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
#include <set>
#include <map>
#include <queue>
#include <math.h>
#include <chrono>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;

const int sz = 1e9;

int ask(int i, int j) {
    cout << "? " << i << ' ' << j << endl;
    fflush(stdout);
    int ans;
    cin >> ans;
    return ans;
}

int main() {
    fast;
    int d = ask(1, 1);
    int l = 2, r = sz, mid, bst = 0;
    while (l <= r) {
        mid = (l + r + 1) / 2;
        int qans = ask(1, mid);
        if (qans == d - (mid - 1)) {
            bst = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    int x = bst, y = 1 + (d - (bst - 1));//check
    swap(x, y);
    int q2 = ask(1, sz), q3 = ask(sz, 1);
    int p = y - 1 + sz - q3, q = x - 1 + sz - q2;
    cout << "! " << x << ' ' << y << ' ' << p << ' ' << q << endl;
    fflush(stdout);
    return 0;
}