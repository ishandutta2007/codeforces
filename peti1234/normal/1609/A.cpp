#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        long long n, po=1, sum=0, maxi=0;
        cin >> n;
        for (int i=1; i<=n; i++) {
            long long x;
            cin >> x;
            while (x%2==0) {
                po*=2, x/=2;
            }
            sum+=x, maxi=max(maxi, x);
        }
        cout << sum+maxi*(po-1) << "\n";
    }
    return 0;
}