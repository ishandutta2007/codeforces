#include <bits/stdc++.h>

using namespace std;
int w, n, maxi;
map<int, int> m;
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            maxi=max(maxi, ++m[x]);
        }
        int db=0, m2=maxi;
        while (m2<n) {
            db++, m2*=2;
        }
        cout << n-maxi+db << "\n";
        m.clear();
        maxi=0;
    }
    return 0;
}