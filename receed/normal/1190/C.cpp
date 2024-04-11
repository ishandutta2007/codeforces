#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ld = long double;

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k;
    string s;
    cin >> n >> k >> s;
    int r1 = -1, l1 = n, l0 = n, r0 = -1;
    rep(i, n) {
        if (s[i] == '1') {
            r1 = max(r1, i);
            l1 = min(l1, i);
        }
        else {
            r0 = max(r0, i);
            l0 = min(l0, i);
        }
    }
    if (r1 == -1 || r0 == -1 || r1 - l1 + 1 <= k || r0 - l0 + 1 <= k) {
        cout << "tokitsukaze";
        return 0;
    }
    if (r1 - l1 + 1 == k + 1 && r0 - l0 + 1 == k + 1 && l1 < k && l0 < k && r0 >= n - k && r1 >= n - k) {
        cout << "quailty";
        return 0;
    }
    cout << "once again";
}