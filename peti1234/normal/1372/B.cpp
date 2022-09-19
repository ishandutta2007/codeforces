#include <bits/stdc++.h>

using namespace std;
int w, n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n;
        int jo=0;
        for (int i=2; i<=sqrt(n); i++) {
            if (n%i==0 && !jo) { jo=1; cout << n/i << " " << n-n/i << "\n";}

        }
        if (!jo) cout << 1 << " " << n-1 << "\n";
    }
    return 0;
}