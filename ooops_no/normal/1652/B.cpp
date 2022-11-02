#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        int now = n - 1;
        map<char, int> cnt;
        for (int i = n - 1; i >= 0; i--) {
            cnt[s[i]]++;
            if (cnt[s[i]] == 1) {
                now = i;
            }
        }
        for (int j = now; j < n; j++) {
            cout << s[j];
        }
        cout << endl;
    }
    return 0;
}