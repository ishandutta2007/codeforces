#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<queue>
using namespace std;
const unsigned long long INF = 10000000000000000;
const int Y = 1000000;
//const long long m = 1000000007;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        bool ans = true;
        int n, m;
        cin >> n >> m;
        long long t = 0, mn = m, mx = m;
        for (int j = 0; j < n; ++j) {
            long long t1, mn1, mx1;
            cin >> t1 >> mn1 >> mx1;
            t1 -= t;
            if (mx + t1 >= mn1 && mn - t1 <= mx1) {
                mx += t1;
                mn -= t1;
                mx = min(mx, mx1);
                mn = max(mn, mn1);
                t += t1;
            }
            else ans = false;
        }
        if (ans)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
/* Thu Feb 06 2020 12:04:32 GMT+0300 (MSK) */