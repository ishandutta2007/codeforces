#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define ld long double
#define ll __int128

mt19937 rnd(51);

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (s[0] != 'R') {
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == 'R') s[i] = 'D';
                else s[i] = 'R';
            }
        }
        int i = 1, j = 1;
        for (int f = 0; f < s.size(); f++) {
            if (s[f] == 'R') j++;
            else i++;
        }
        if (i == 1 || j == 1) {
            cout << n << endl;
        } else {
            int d = n - i, r = n - j, ans = 0, ind = 0;
            i = 1, j = 1;
            while (s[ind] == 'R') {
                j++;
                ind++;
            }
            ans += j + r;
            ans += (d + 1) * (r + 1);
            ind++;
            while (ind < s.size()) {
                if (s[ind] == 'D') {
                    ans += r + 1;
                } else {
                    ans += d + 1;
                }
                ind++;
            }
            cout << ans << endl;
        }
    }
    return 0;
}