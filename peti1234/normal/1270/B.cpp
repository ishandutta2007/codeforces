#include <bits/stdc++.h>

using namespace std;
int w, el, n;
bool jo;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> el, jo=0;
        for (int i=1; i<n; i++) {
            int x; cin >> x;
            if (!jo && abs(x-el)>1) {
                cout << "YES\n";
                cout << i << " " << i+1 << "\n";
                jo=1;
            }
            el=x;
        }
        if (!jo) {
            cout << "NO\n";
        }
    }
    return 0;
}