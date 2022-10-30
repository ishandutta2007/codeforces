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

const int sz = 1025;
int prv[sz], dp[sz];
int n, k, x;

int main() {
    fast;
    cin >> n >> k >> x;
    foru(i, 0, n) {
        int y;
        cin >> y;
        prv[y]++;
    }
    while (k--) {
        bool is = 1;
        foru(i, 0, sz) {
            if (is == (prv[i] & 1)) {
                dp[i] += (prv[i] >> 1);
                dp[i ^ x] += ((prv[i] + 1) >> 1);
            }
            else {
                dp[i] += ((prv[i] + 1) >> 1);
                dp[i ^ x] += (prv[i] >> 1);
            }
            is ^= (prv[i] & 1);
        }
        foru(i, 0, sz) {
            prv[i] = dp[i];
            dp[i] = 0;
        }
    }
    ford(i, sz - 1, 0) {
        if (prv[i]) {
            cout << i << ' ';
            break;
        }
    }
    foru(i, 0, sz) {
        if (prv[i]) {
            cout << i << ' ';
            break;
        }
    }
    return 0;
}