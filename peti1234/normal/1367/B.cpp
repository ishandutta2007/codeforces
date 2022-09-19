#include <bits/stdc++.h>

using namespace std;
int w, n, o, e;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, o=0, e=0;
        for (int i=0; i<n; i++) {
            int x;
            cin >> x;
            if ((x%2)!=(i%2)) {
                if (i%2) o++;
                else e++;
            }
        }
        if (o==e) cout << o << "\n";
        else cout << -1 << "\n";
    }
    return 0;
}