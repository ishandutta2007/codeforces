#include <bits/stdc++.h>

using namespace std;
int w, n, k;
set<int> s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k;
        int x;
        for (int i=1; i<=n; i++) {
            cin >> x;
            s.insert(x);
        }
        bool jo=0;
        for (auto x:s) {
            if (s.find(x+k)!=s.end()) {
                jo=1;
            }
        }
        cout << (jo ? "YES" : "NO") << "\n";
        s.clear();
    }
    return 0;
}