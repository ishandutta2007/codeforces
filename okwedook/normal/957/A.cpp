#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

int main() {
    //ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 1; i < n; ++i)
        if (s[i] == s[i - 1] && s[i] != '?') {
            cout << "No";
            return 0;
        }
    for (int i = 0; i < n; ++i) {
        if (s[i] == '?') {
            if (i == 0 || i == n - 1) {
                cout << "Yes";
                return 0;
            }
            if (s[i + 1] == '?' || s[i - 1] == '?' || s[i + 1] == s[i - 1]) {
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";
    return 0;
}