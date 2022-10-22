#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define endl "\n"
#define int long long
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const int inf = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(2);
    int t = 1; cin >> t;
    while (t --> 0) {
        int n; cin >> n;
        vector <int> a(n), mex(1007), ans;
        for (auto& x : a) {
            cin >> x;
            mex[x]++;
        }
        for (int i = 0; i < n; ++i) {
            int j = 0;
            while (mex[j] and j < n) ++j;
            //if (a[i] == j) continue;
            if (j == n) {
                for (int k = 0; k < n; ++k) if (a[k] != k) {
                    mex[j]++; mex[a[k]]--; a[k] = j; i--;
                    ans.push_back(k);
                    break;
                }
            }
            else {
                mex[j]++; mex[a[j]]--;
                a[j] = j;
                ans.push_back(j);
            }
        }
        cout << ans.size() << endl;
        for (auto x : ans) cout << x + 1 << " ";
        cout << endl;
    }
}