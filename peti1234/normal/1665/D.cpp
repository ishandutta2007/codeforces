#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        long long ans=0;
        for (long long x=1; x<(1<<30); x*=2) {
            cout.flush() << "? " <<  x-ans << " " << 3*x-ans << "\n";
            long long ert;
            cin >> ert;
            if (ert%(2*x)==0) {
                ans+=x;
            }
        }
        cout.flush() << "! " << ans << "\n";
    }
    return 0;
}