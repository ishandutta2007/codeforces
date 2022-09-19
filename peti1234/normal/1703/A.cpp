#include <bits/stdc++.h>

using namespace std;
void solve() {
    string s;
    cin >> s;
    cout << ((s[0]=='y' || s[0]=='Y') && (s[1]=='e' || s[1]=='E') && (s[2]=='s' || s[2]=='S') ? "YES" : "NO") << "\n";
}
int main()
{
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}