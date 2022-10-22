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
    int tt; cin >> tt;
    while(tt--) {
        int n; cin >> n;
        vector <int> a(n);
        for (auto& x : a) cin >> x;
        sort(a.begin(), a.end());
        int cnt = n - 1;
        for (int i = 1; i < n; ++i)
            if (a[i] - a[i - 1] > 1) --cnt;
        if (cnt < n - 1) cout << "NO";
        else cout << "YES";
        cout << "\n";

    }
    return 0;
}