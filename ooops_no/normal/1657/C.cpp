#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define ld double
#define ll __int128

mt19937 rnd(51);

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int i = 0, cnt = 0;
        while (i + 1 < n) {
            cnt++;
            if (s[i] == '(') {
                i += 2;
                continue;
            }
            int j = i + 1;
            while (j < n && s[j] == '(') {
                j++;
            }
            if (j == n) {
                cnt--;
                break;
            }
            i = j + 1;
         }
        cout << cnt << ' ' << max(0ll, n - i) << endl;
    }
    return 0;
}