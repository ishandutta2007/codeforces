#include <bits/stdc++.h>

using namespace std;
int w, a, b;
bool pr(int x, int y) {
    bool s=(x+y)%2;
    if (s && !b || !s && !a) {
        return false;
    }
    cout << x << " " << y << "\n";
    if (s) b--;
    else a--;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> a >> b;
        swap(a, b);
        if (a>3*b+1 || b>3*a+1) cout << "NO\n";
        else {
            cout << "YES\n";
            int kezd=(a>=b ? 2 : 3), veg;
            for (int i=kezd; ; i++) {
                if (!pr(2, i)) {
                    veg=i-1;
                    break;
                }
            }
            for (int i=kezd; i<=veg; i++) {
                pr(1, i);
                pr(3, i);
            }
        }
    }
    return 0;
}