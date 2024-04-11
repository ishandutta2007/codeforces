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
    int n, m; cin >> n >> m;
    vector <int> a(n), b(m);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    int i = 1, j = 0, ans = 0, curs1 = a[0], curs2 = 0;
    while (i < n or j < m){
        if (curs1 > curs2) 
            curs2 += b[j++];
        else if (curs2 > curs1)
            curs1 += a[i++];
        else {
            ++ans;
            curs1 = a[i++], curs2 = 0;
        }
    }
    cout << ans + 1 << "\n";
    return 0;
}