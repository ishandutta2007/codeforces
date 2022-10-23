#include <bits/stdc++.h>

using namespace std;
int v[1005];
int main()
{
    int w;
    cin >> w;
    while (w--) {
        int n, maxi=0;
        cin >> n;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            v[x]=i;
        }
        for (int i=1; i<=1000; i++) {
            for (int j=i; j<=1000; j++) {
                if (__gcd(i, j)==1 && v[i] && v[j]) {
                    maxi=max(maxi, v[i]+v[j]);
                }
            }
        }
        cout << (maxi==0 ? -1 : maxi) << "\n";
        memset(v, 0, sizeof(v));
    }
    return 0;
}