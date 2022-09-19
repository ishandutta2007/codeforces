#include <bits/stdc++.h>
 
using namespace std;
long long w, n, k, s, e=1, maxi, t[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k;
        maxi=-1e8;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        s=max(e, n-k-1);
        for (long long i=s; i<=n; i++) {
            for (long long j=i+1; j<=n; j++) {
                maxi=max(maxi, i*j-k*(t[i]|t[j]));
            }
        }
        cout << maxi << "\n";
    }
    return 0;
}