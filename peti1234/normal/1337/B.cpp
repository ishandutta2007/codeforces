#include <bits/stdc++.h>

using namespace std;
int w, x, n, m;
int main()
{
    cin >> w;
    while(w--) {
        cin >> x >> n >> m;
        for (int i=1; i<=n; i++) if (x>20) x/=2, x+=10;
        x-=10*m;
        if (x>0) cout << "NO" << "\n";
        else cout << "YES" << "\n";
    }
    return 0;
}