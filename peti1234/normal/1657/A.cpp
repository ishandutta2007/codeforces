#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    long long w, x, y;
    cin >> w;
    while (w--) {
        cin >> x >> y;
        if (x==0 && y==0) cout << 0 << "\n";
        else {
            long long s=x*x+y*y, p=sqrt(s);
            cout << (p*p==s ? 1 : 2) << "\n";
        }
    }
    return 0;
}