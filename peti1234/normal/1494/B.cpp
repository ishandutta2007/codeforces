#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n, a, x, b, y;
        cin >> n >> a >> x >> b >> y;
        bool baj=0;
        if (max(a, b)-min(x, y)==n) {
            baj=1;
        }
        if (max(x, y)-min(a, b)==n) {
            baj=1;
        }
        int ok=max(0, x-n+2)+max(0, y-n+2), on=min(2, x)+min(2, y);
        int sk=max(0, a-n+2)+max(0, b-n+2), sn=min(2, a)+min(2, b);
        cout << (baj || ok>sn || sk>on ? "NO" : "YES") << "\n";
    }
    return 0;
}