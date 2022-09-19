#include <bits/stdc++.h>

using namespace std;
int w, n, d, x;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> d;
        for (int i=1; i<=n; i++) {
            cin >> x;
            bool jo=0;
            if (x>=100) {
                jo=1;
            } else  while (x>0) {
                if (x%10==d || x/10==d) {
                    jo=1;
                }
                x-=d;
            }
            cout << (jo? "YES" : "NO") << "\n";
        }
    }
    return 0;
}