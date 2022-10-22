#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long
const int root = 5e2;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector <int> a(n);
    for (auto &x: a) cin >> x;
    vector <vector <int>> dp(root + 1);
    int q; cin >> q;
    vector <vector <int>> qs(q);
    vector <int> ans(q), id(q);
    for (int i = 0; i < q; ++i){
        int x, y; cin >> x >> y;
        qs[i] = {y, x, i};
    }
    sort(qs.begin(), qs.end());
    for (int i = 0; i < q; ++i){
        id[qs[i][2]] = i;
    }
    vector <int> last(n);
    for (int i = 0; i < q; ++i){
        int x = qs[i][1] - 1, y = qs[i][0];
        if (qs[i][0] > root){
            for (int j = x; j < n; j += y){
                ans[i] += a[j];
            }
        } else {
            if (!i or (qs[i][0] != qs[i - 1][0])){
                for (int j = 0; j < n; ++j){
                    last[j] = a[j];
                    if (j - y >= 0) last[j] += last[j - y];
                }
            }
            int l = x + (n - x - 1) / y * y;
            ans[i] = last[l] - last[x] + a[x];
        }
    }
    for (int i = 0; i < q; ++i){
        cout << ans[id[i]] << '\n';
    }
    return 0;
}