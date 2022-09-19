#include <bits/stdc++.h>

using namespace std;
int w, n, o, e;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n, o=0, e=0;
        for (int i=1; i<=n; i++) {
            int x; cin >> x;
            if (x%2) o++;
            else e++;
        }
        if (o && e) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}