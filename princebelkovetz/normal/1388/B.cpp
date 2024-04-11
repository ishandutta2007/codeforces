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
    while (tt --> 0){
        int n; cin >> n;
        string ans;
        for (int i = 0; i < n; ++i) ans += '9';
        int last = n - 1;
        while (n > 1) {
            ans[last] = '8';
            --last;
            n -= 4;
        }
        if (n > 0) ans[last] = '8';
        cout << ans << "\n";
    }
    return 0;
}