#include <bits/stdc++.h>

using namespace std;
void solve() {
    set<string> s[3];
    int n;
    cin >> n;
    for (int i=0; i<3; i++) {
        for (int j=0; j<n; j++) {
            string x;
            cin >> x;
            s[i].insert(x);
        }
    }
    for (int i=0; i<3; i++) {
        int ans=0;
        for (auto x:s[i]) {
            int db=0;
            for (int j=0; j<3; j++) {
                if (s[j].count(x)) {
                    db++;
                }
            }
            if (db==1) ans+=3;
            if (db==2) ans++;
        }
        cout << ans << " ";
    }
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}