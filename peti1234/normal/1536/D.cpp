#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int w, n, t[c];
set<int> s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        bool jo=1;
        s.clear();
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            s.insert(t[i]);
            if (i==1 || t[i]==t[i-1]) {
                continue;
            }
            int a=min(t[i], t[i-1]), b=max(t[i], t[i-1]);
            int x=*s.upper_bound(a);
            if (x!=b) {
                jo=0;
            }
        }

        cout << (jo ? "YES" : "NO") << "\n";
    }
    return 0;
}
/*
1
4
2 1 2 3
*/