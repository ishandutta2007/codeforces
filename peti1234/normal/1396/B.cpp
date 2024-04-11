#include <bits/stdc++.h>

using namespace std;
int w, n, maxi, sum;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n, maxi=0, sum=0;
        for (int i=1; i<=n; i++) {
            int x; cin >> x;
            sum+=x;
            maxi=max(maxi, x);
        }
        if (2*maxi>sum) cout << "T\n";
        else {
            if (sum%2) cout << "T\n";
            else cout << "HL\n";
        }
    }
    return 0;
}