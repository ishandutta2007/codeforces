#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 2e4;
int arr[MAXN];

main() {
    int t;
    cin >> t;
    for (int ts = 0; ts < t; ++ts) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans1 = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '<') {
                ans1++;
            } else {
                break;
            }
        }
        int ans2 = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '>') {
                ans2++;
            } else {
                break;
            }
        }
        cout << min(ans1, ans2) << endl;
    }
    return 0;
}