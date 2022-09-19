#include <bits/stdc++.h>

using namespace std;
int w, n, m, jo, a, b, c, d;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n >> m, jo=0;
        for (int i=1; i<=n; i++) {
            cin >> a >> b >> c >> d;
            if (b==c) jo++;
        }
        if (m%2==0 && jo) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}