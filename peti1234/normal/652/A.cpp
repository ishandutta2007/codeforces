#include <bits/stdc++.h>

using namespace std;
int x, y, a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> x >> y >> a >> b;
    if (a<=b && x+8*a<y) {
        cout << -1 << "\n";
        return 0;
    }
    for (int i=4; ; i++) {
        if (x<y) {
            if (i%24<12) x+=a;
            else x-=b;
        } else {
            cout << i/24 << "\n";
            return 0;
        }
    }
    return 0;
}