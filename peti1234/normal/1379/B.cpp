#include <bits/stdc++.h>

using namespace std;
int w;
long long l, r, m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> l >> r >> m;
        for (int i=l; i<=r; i++) {
            long long x=(m/i)*i, y=x+i;
            if (r-l>=y-m) {
                cout << i << " " << l << " " << y+l-m << "\n";
                break;
            }
            if (r-l>=m-x) {
                cout << i << " " << r << " " << x+r-m << "\n";
                break;
            }
        }
    }
    return 0;
}
/*
1 4 6 13
*/