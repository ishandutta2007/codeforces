#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> perm(2 * n);
    for (int &x : perm) {
        cin >> x;
        --x;
    }

    vector<int> want(2*n);
    iota(want.begin(), want.end(), 0);
    vector<int> p = perm;
    int sol1 = 0;
    if (p == want) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < 4 * n; ++i) {
        for (int j = 0; j < 2 * n; j += 2)
            swap(p[j], p[j+1]);
        sol1++;
        if (want == p)
            break;
        for (int j = 0; j < n; ++j)
            swap(p[j], p[j+n]);
        sol1++;
        if (want==p)
            break;
        if (i == 4 * n - 1)
            sol1 = 1e18;
    }
    p =perm;
    int sol2 = 0;
    for (int i = 0; i < 4 * n; ++i) {
         for (int j = 0; j < n; ++j)
            swap(p[j], p[j+n]);
        
        sol2++;
        if (want == p)
            break;
       for (int j = 0; j < 2 * n; j += 2)
            swap(p[j], p[j+1]);
        sol2++;
        if (want==p)
            break;
        if (i == 4 * n - 1)
            sol2 = 1e18;
    }
    int sol = min(sol1, sol2);
    if (sol == 1e18)
        sol = -1;
    cout << sol << endl;
}