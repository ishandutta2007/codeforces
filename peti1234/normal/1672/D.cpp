#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, a[c], b[c];
multiset<int> m;
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> a[i];
        }
        for (int i=1; i<=n; i++) {
            cin >> b[i];
        }
        bool jo=1;
        int pa=n, pb=n;
        while (pb>0) {
            while (a[pa]!=b[pb]) {
                if (m.find(a[pa])!=m.end()) {
                    m.erase(m.find(a[pa]));
                } else {
                    jo=0;
                    break;
                }
                pa--;
            }
            if (!jo) {
                break;
            }
            pa--, pb--;
            while (b[pb]==b[pb+1]) {
                m.insert(b[pb]);
                pb--;
            }
        }

        m.clear();
        cout << (jo ? "YES" : "NO") << "\n";
    }
    return 0;
}