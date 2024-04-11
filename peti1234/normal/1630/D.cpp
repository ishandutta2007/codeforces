#include <bits/stdc++.h>

using namespace std;
const int c=1000005;
long long w, n, m, t[c], cnt[c], mini[c], sum, k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }

        for (int i=1; i<=m; i++) {
            long long x;
            cin >> x;
            k=__gcd(k, x);
        }

        for (int i=0; i<k; i++) {
            mini[i]=1e9;
        }
        for (int i=1; i<=n; i++) {
            int s=i%k;
            if (t[i]<0) cnt[s]++;
            mini[s]=min(mini[s], abs(t[i]));
            sum+=abs(t[i]);
        }
        long long ert1=0, ert2=0;
        for (int i=0; i<k; i++) {
            if (cnt[i]%2) ert1+=mini[i];
            else ert2+=mini[i];
        }

        cout << sum-2*min(ert1, ert2) << "\n";


        for (int i=0; i<=n; i++) {
            t[i]=0, cnt[i]=0, mini[i]=0;
            sum=0, k=0;
        }
    }
    return 0;
}