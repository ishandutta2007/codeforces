#include <bits/stdc++.h>

using namespace std;
int w, n, m, a, b, x, y;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> a >> m, b=a;
        for (int i=1; i<=m; i++) {
            cin >> x >> y;
            if (x<=a && a<=y) a=x;
            if (x<=b && b<=y) b=y;
        }
        cout << b-a+1 << "\n";
    }
    return 0;
}