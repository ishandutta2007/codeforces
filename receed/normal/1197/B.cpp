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
	int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n)
        cin >> a[i];
    int l = 0, r = n - 1;
    while (l + 1 < n && a[l] < a[l + 1])
        l++;
    while (r > 0 && a[r] < a[r - 1])
        r--;
    if (r <= l)
        cout << "YES";
    else
        cout << "NO";
}