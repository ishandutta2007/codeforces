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
struct point {
    int x; bool f;
};
bool cmp(point a, point b) {
    return a.x < b.x;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(6);
    int tt; cin >> tt;
    while (tt--) {
        int a; cin >> a;
        vector <int> bits;
        bool c = false;
        while (a) {
            bits.push_back(a % 2);
            a /= 2;
            if (!bits.back()) c = true;
        }
        int ans = 0, cur = 1;
        for (int i = 0; i < bits.size(); ++i, cur *= 2) {
            ans += cur;
        }
        if (c) {
            cout << ans;
        }
        else {
            int ok = 0;
            for (int i = 2; i * i <= ans; ++i) {
                if (ans % i) continue;
                ok = ans / i;
                break;
            }
            if (ok) cout << ok;
            else cout << 1;
        }
        cout << "\n";
    }
    
    return 0;
}