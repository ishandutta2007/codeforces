#include <bits/stdc++.h>

using namespace std;
int w, n;
map<int, int> m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            m[x]++;
        }
        bool jo=0;
        for (auto p:m) {
            if (p.second>=3 && !jo) {
                jo=1;
                cout << p.first << "\n";
            }
        }
        if (!jo) {
            cout << -1 << "\n";
        }
        m.clear();
    }
    return 0;
}