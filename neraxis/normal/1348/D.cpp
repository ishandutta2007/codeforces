#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        ii cur = {1, 1};
        vector<int> ans;
        while (1) {
            int a = cur.x;
            int b = n - cur.y;
            if (b <= 2 * a) {
                int u = n - cur.y;
                ans.pb(u - a);
                break;
            } else if (b <= 4 * a) {
                int u = b / 2;
                ans.pb(u - a);
                ans.pb(b - 2 * u);
                break;
            } else {
                ans.pb(a);
                cur.x = 2 * cur.x;
                cur.y += cur.x;
            }
        }
        cout << ans.size() << '\n';
        for (int e : ans) cout << e << ' ';
        cout << '\n';
    }
    return 0;
}