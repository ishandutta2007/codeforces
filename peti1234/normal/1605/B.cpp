#include <bits/stdc++.h>

using namespace std;
int w, n, db;
string s;
vector<int> sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> s;
        for (int i=0; i<n; i++) if (s[i]=='1') db++;
        for (int i=0; i<n; i++) if (i+db<n && s[i]=='1' ||i+db>=n && s[i]=='0') sz.push_back(i);
        if (sz.size()>0) {
            cout << 1 << "\n";
            cout << sz.size() << " ";
            for (auto x:sz) cout << x+1 << " ";
            cout << "\n";
        } else {
            cout << 0 << "\n";
        }
        sz.clear(), db=0;
    }
    return 0;
}