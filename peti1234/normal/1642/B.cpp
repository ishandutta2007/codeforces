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
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            s.insert(x);
        }
        int si=s.size();
        for (int i=1; i<=n; i++) {
            cout << max(i, si) << " ";
        }
        cout << "\n";
        s.clear();
    }
    return 0;
}