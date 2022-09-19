#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int w;
    cin >> w;
    while (w--) {
        long long x, y;
        cin >> x;
        y=sqrt(x);
        bool jo=1;
        for (int i=2; i*i<=y; i++) {
            if (y%i==0) {
                jo=0;
            }
        }
        cout << (jo && y>1 && y*y==x ? "YES" : "NO") << "\n";
    }
    return 0;
}