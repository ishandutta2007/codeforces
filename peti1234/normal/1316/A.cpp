#include <bits/stdc++.h>

using namespace std;
int w, n, m, e, s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> m >> e, s=0;
        for (int i=1; i<n; i++) {
            int x; cin >> x;
            s+=x;
        }
        cout << min(m, e+s) << "\n";
    }
    return 0;
}