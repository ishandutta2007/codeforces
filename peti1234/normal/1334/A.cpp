#include <bits/stdc++.h>

using namespace std;
int w, n, x, y, a, b;
bool c=true;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, x=0, y=0;
        c=true;
        for (int i=1; i<=n; i++) {
            cin >> a >> b;
            if (a<x || b<y || a-x<b-y) c=false;
            x=a, y=b;
        }
        if (c) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}
// Knny a feladat.