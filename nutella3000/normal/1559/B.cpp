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
#define ull unsigned long long
mt19937 rnd;
 
const int inf = 1e15 + 3, mod = 1e9 + 7;
const int max_n = 2e5 + 3, log_n = 20;

void run() {
    int n;
    string s;
    cin >> n >> s;
    s += 'B';
    int f = find_if_not(all(s), [](char i) { return i == '?'; }) - s.begin();
    for (int i = 0; i < f; ++i)
        cout << ((((f - i) & 1) ^ s[f] == 'B') ? 'B' : 'R');
    for (int i = f; i < n; ++i) {
        if (s[i] != '?') cout << s[i];
        else {
            s[i] = (s[i - 1] == 'B' ? 'R' : 'B');
            cout << s[i];
        }
    }
    cout << endl;
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
        run();
    }
}