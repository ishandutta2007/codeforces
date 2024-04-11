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

const int inf = 2e9 + 3;
void run() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    vector<bool> used(n);
    for (int i = 0; i < n; ++i) {
        if (t[i] == '0') continue;
        if (s[i] == '0') {
            used[i] = true;
        }else {
            if (i && s[i - 1] == '1' && !used[i - 1]) used[i - 1] = true;
            else if (i + 1 < n && s[i + 1] == '1') used[i + 1] = true;
        }
    }
    cout << count(all(used), true) << endl;
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