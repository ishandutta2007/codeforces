#include <bits/stdc++.h>

using namespace std;
int w, n;
string s;
void solve() {
    cin >> n;
    cin >> s;
    int f=n/2;
    for (int i=0; i<f; i++) {
        if (s[i]=='0') {
            cout << i+1<< " " << n << " " << i+2 << " " << n << "\n";
            return;
        }
    }
    for (int i=f; i<n; i++) {
        if (s[i]=='0') {
            cout << 1 << " " << i+1 << " " << 1 << " " << i << "\n";
            return;
        }
    }
    cout << 1 << " " << n-1 << " " << 2 << " " << n << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}