#include <bits/stdc++.h>

using namespace std;
int w, n, x, y;
bool v;
string s;
vector<pair<int, int> > sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n;
        x=0, y=0, v=false, s.clear(), sz.clear();
        sz.push_back({0, 0});
        for (int i=1; i<=n; i++) {
            int a, b;
            cin >> a >> b;
            sz.push_back({a, b});
        }
        sort(sz.begin(), sz.end());
        for (int i=1; i<=n; i++) {
            int fi=sz[i].first, se=sz[i].second;
            if (se<y) {
                v=true;
                break;
            }
            while(x!=fi) s+='R', x++;
            while(y!=se) s+='U', y++;
        }
        if (v) cout << "NO" << "\n";
        else {
            cout << "YES" << "\n";
            for (int i=0; i<s.size(); i++) cout << s[i];
            cout << "\n";
        }
    }
    return 0;
}