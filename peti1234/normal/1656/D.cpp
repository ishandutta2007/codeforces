#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        long long x, po=1;
        cin >> x;
        while (x%2==0) {
            x/=2, po*=2;
        }
        if (x==1) cout << -1 << "\n";
        else cout << min(x, 2*po) << "\n";
    }
    return 0;
}