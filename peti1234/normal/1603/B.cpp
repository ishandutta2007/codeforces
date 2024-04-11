#include <bits/stdc++.h>

using namespace std;
long long w, x, y;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> x >> y;
        if (x==y) cout << x << "\n";
        else if (x>y) cout << x+y << "\n";
        else if (y%x==0) cout << y << "\n";
        else {
            long long mid=(x+y)/2;
            mid+=(y-mid-1)/x*x;
            cout << mid << "\n";
        }
    }
    return 0;
}