#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        long long n, sum=0, maxi=0, x;
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> x;
            sum+=x;
            maxi=max(maxi, x);
        }
        if (sum==0) cout << 0 << "\n";
        else {
            cout << max((long long)1, 2*maxi-sum) << "\n";
        }
    }
    return 0;
}