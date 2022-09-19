#include <bits/stdc++.h>

using namespace std;
string s[100005];
set<string> x;
void solve() {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> s[i];
        x.insert(s[i]);
    }
    for (int i=1; i<=n; i++) {
        bool jo=0;
        int si=s[i].size();
        for (int j=1; j<si; j++) {
            if (x.find(s[i].substr(0, j))!=x.end() && x.find(s[i].substr(j, si-j))!=x.end()) {
                jo=1;
            }
        }
        cout << jo;
    }
    cout << "\n";


    x.clear();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}