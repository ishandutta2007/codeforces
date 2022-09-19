#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w, a, b, c, d, e, f;
    cin >> w;
    while (w--) {
        cin >> a >> b >> c >> d >> e >> f;
        int dc=1, dd=1;
        int cnt=0;
        while (c!=e && d!=f) {
            if (c==1) dc=1;
            if (c==a) dc=-1;
            if (b==1) dd=1;
            if (d==b) dd=-1;
            c+=dc, d+=dd, cnt++;
        }
        cout << cnt << "\n";
    }
    return 0;
}