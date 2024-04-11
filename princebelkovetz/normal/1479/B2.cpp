#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cassert>
using namespace std;
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    int n; cin >> n;
    vector <vector <int>> inds(n + 1);
    vector <int> cur(n + 1), a(n);
    for (auto& x : a) cin >> x;
    vector <int> b;
    for (int i = 0; i < n; ++i) {
        b.push_back(a[i]);
        int j = i;
        while (j < n and a[j] == a[i])
            j++;
        i = j - 1;
    }
    a = b, n = b.size();
    for (int i = 0; i < n; ++i) {
        inds[a[i]].push_back(i);
    }
    int l = 0, r = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        if (l == x) cur[x]++;
        else if (r == x) cur[x]++;
        else if (cur[l] == inds[l].size()) {
            l = x, cur[x]++, ans++;
        }
        else if (cur[r] == inds[r].size()) {
            r = x, cur[x]++, ans++;
        }
        else {
            int dl = inds[l][cur[l]] - i;
            int dr = inds[r][cur[r]] - i;
            if (dl < dr) r = x;
            else l = x;
            ans++; cur[x]++;
        }
    }
    cout << ans << '\n';
    return 0;
}