#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <string>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#include <deque>
#include <iterator>
#include <sstream>
#define endl "\n"
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(6);
    int n; cin >> n;
    vector <int> a(n), l(n, -1), r(n, -1);
    for (auto& x : a) cin >> x;
    stack <int> left, right;
    for (int i = 0; i < n; ++i) {
        while (!left.empty() and a[left.top()] >= a[i])
            left.pop();
        if (!left.empty()) l[i] = left.top();
        left.push(i);
    }
    for (int i = n - 1; i >= 0; --i) {
        while (!right.empty() and a[right.top()] >= a[i])
            right.pop();
        if (!right.empty()) r[i] = right.top();
        right.push(i);
    }
    vector <int> ansl(n), ansr(n);
    for (int i = 0; i < n; ++i) {
        if (l[i] == -1) 
            ansl[i] = a[i] * (i + 1);
        else 
            ansl[i] = ansl[l[i]] + (i - l[i]) * a[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        if (r[i] == -1)
            ansr[i] = a[i] * (n - i);
        else
            ansr[i] = ansr[r[i]] + (r[i] - i) * a[i];
    }
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        int mx = ansr[ans] + ansl[ans] - a[ans];
        int cur = ansr[i] + ansl[i] - a[i];
        if (cur > mx) ans = i;
    }
    int cur = a[ans];
    for (int i = ans; i < n; ++i) {
        a[i] = min(a[i], cur);
        cur = a[i];
    }
    cur = a[ans];
    for (int i = ans; i >= 0; --i) {
        a[i] = min(a[i], cur);
        cur = a[i];
    }
    for (auto x : a) cout << x << ' ';
    return 0;
}