#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair<int, int>
#define all(_v) _v.begin(), _v.end()
#define sz(a) ((int)a.size())
#define what_is(x) cout << #x << " is " << x << endl;
typedef long double ld;
 
const ll inf = 1e17 + 7;

bool win(int a, int b) {
    return a != 0;
}

bool lose(int a, int b) {
    return a % (b + 1) % 2 == 0;
}

void solve() {
    int a, b;
    cin >> a >> b;
    vector<pii> c;

    while(a != 0 && b != 0) {
        if (a < b) swap(a, b);
        c.emplace_back(a / b, b);
        a = a % b;
    }

    bool to_win = true;
    for(int i = (int)c.size() - 1;i >= 0;i--) {
        if (to_win) {
            to_win = !win(c[i].first, c[i].second);
        }else {
            to_win = !lose(c[i].first, c[i].second);
        }
    }

    cout << (!to_win ? "First" : "Second") << endl;
}


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int t;
    cin >> t;
    while(t--)
        solve();
}