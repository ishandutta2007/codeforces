#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())
typedef long double ld;
 
const int inf = 1e17 + 7;
const int mod = 1e9 + 7;



signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    string s;
    cin >> s;
    int n = s.size();
    int res = 0;
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0;i < n;i++)
        cnt2 += s[i] == 'Q';

    for(int i = 0;i < n;i++) {
        if (s[i] == 'Q') {
            cnt1++;
            cnt2--;
        }
        if (s[i] == 'A') {
            res += cnt1 * cnt2;
        }
    }

    cout << res << endl;
}