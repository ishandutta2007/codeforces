#include <bits/stdc++.h>

using namespace std;
int w, n, el;
bool jo;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> el, jo=0;
        for (int i=1; i<n; i++) {
            int x; cin >> x;
            if (x>=el) jo=1;
            el=x;
        }
        if (jo) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}