#include <bits/stdc++.h>

using namespace std;
int w, n;
set<int> s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        int x;
        int e=0;
        for (int i=1; i<=n; i++) {
            cin >> x;
            if (x==1) e++;
            s.insert(x);
        }
        bool k=0;
        for (auto p:s) {
            if (s.find(p+1)!=s.end()) {
                k=1;
            }
        }
        cout << (e && k ? "NO" : "YES") << "\n";
        s.clear();
    }
    return 0;
}