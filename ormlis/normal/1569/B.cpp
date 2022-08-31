#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;
//using namespace __gnu_pbds;


typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

/*
typedef tree<
        pair<ll, int>,
        null_type,
        less<pair<ll, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
*/

const int INFi = 1e9 + 5;
const int md = 998244353;
const ll INF = 2e18;
const int maxN = 2e6 + 1;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n; cin >> n;
    int cnt1 = 0, cnt2 = 0;
    vector<int> a(n);
    vector<int> to;
    range(i, n) {
        char y; cin >> y;
        int x = y - '0';
        a[i] = x;
        if (x == 1) cnt1++;
        else {
            to.push_back(i);
            cnt2++;
        }
    }
    if (cnt2 == 1 || cnt2 == 2) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    vector<vector<char>> b(n, vector<char> (n, '='));
    for(int i = 1; i <= (int)to.size(); ++i) {
        int x = to[i - 1];
        int y = to[i% (int)to.size()];
        b[x][y] = '+';
        b[y][x] = '-';
    }
    range(i, n) b[i][i] = 'X';
    range(i, n) {
        range(j, n) {
            cout << b[i][j];
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}