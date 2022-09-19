#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w, x1, x2, x3, y1, y2, y3;
    cin >> w;
    while (w--) {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        if (y1==y2 && y3<y1) cout << abs(x1-x2) << "\n";
        else if (y1==y3 && y2<y1) cout << abs(x1-x3) << "\n";
        else if (y2==y3 && y1<y2) cout << abs(x2-x3) << "\n";
        else cout << 0 << "\n";
    }
    return 0;
}
/*
1
14 1
11 2
13 2
*/