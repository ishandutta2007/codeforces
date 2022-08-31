#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

// using namespace __gnu_pbds;
/*
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
*/

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int INFi = 2e9 + 5;
const int maxN = 1e5 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k = 0;
    int a = 0;
    range(i, n / 2) {
        if (s[i] == s[n - 1 - i]) {
            if (s[i] == '0') k += 2;
            continue;
        }
        a++;
    }
    if (n % 2 == 1 && s[n/2] == '0') k++;
    if (k == 0) {
        cout << "ALICE\n";
        return;
    }
    if (k == 1) {
        if (a > 1) cout << "ALICE\n";
        else if (a == 1) cout << "DRAW\n";
        else if (a == 0) cout << "BOB\n";
        return;
    }
    if (k % 2 == 0 && a == 0) {
        cout << "BOB\n";
        return;
    }
    cout << "ALICE\n";
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