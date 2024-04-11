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
    int n, sum = 0; cin >> n;
    vector <ld> a(n);
    vector <int> ans(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ans[i] = trunc(a[i]);
        sum += ans[i];
    }
    for (int i = 0; i < n and sum != 0; ++i) {
        if (a[i] != trunc(a[i])) {
            if (sum < 0 and a[i] > 0) {
                ans[i]++;
                sum++;
            }
            else if (sum > 0 and a[i] < 0) {
                ans[i]--;
                sum--;
            }
        }
    }
    for (auto x : ans) cout << x << "\n";
    return 0;
}