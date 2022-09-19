#include <bits/stdc++.h>

using namespace std;
const int c=10002;
int w, n, sum, t[c], mid;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n, sum=0;
        for (int i=1; i<=n; i++) cin >> t[i], sum+=t[i];
        if (sum%n) {
            cout << -1 << "\n";
        } else {
            mid=sum/n;
            cout << 3*n-3 << "\n";
            for (int i=2; i<=n; i++) {
                int pl=i-t[i]%i;
                if (pl==i) pl=0;
                cout << 1 << " " << i << " " << pl << "\n";
                t[i]+=pl;
                cout << i << " " << 1 << " " << t[i]/i << "\n";
            }
            for (int i=2; i<=n; i++) {
                cout << 1 << " " << i << " " << mid << "\n";
            }
        }
    }
    return 0;
}