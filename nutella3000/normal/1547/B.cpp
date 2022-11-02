#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define size(a) (int) a.size()
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define all(a) begin(a), end(a)
#define mp make_pair
#define pb emplace_back
#define ld long double
mt19937 rnd;
 
const int inf = 1e15 + 3, mod = 1e9 + 7;
const int max_n = 2e5 + 3;

bool run() {
    string s;
    cin >> s;
    int l = find(all(s), 'a') - s.begin(), r = find(all(s), 'a') - s.begin();
    for (int i = 0; i < size(s); ++i) {
        int id = find(all(s), char('a' + i)) - s.begin();
        if (id >= size(s)) return false;
        if (id != r && id != l - 1) return false;
        if (id == r) ++r;
        else --l;
    }
    return true;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(20);
 
#ifdef ahahaha
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 
    int t = 1;
    cin >> t;
    while (t--) {
        cout << (run() ? "Yes" : "No") << endl;
    }
}