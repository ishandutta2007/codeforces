#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, k, sum, regi[c], uj[c], pref[c], ans[c], mod=998244353;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    regi[0]=1;
    while (sum<n) {
        for (int i=0; i<=n; i++) {
            pref[i]=regi[i];
            if (i>=k) {
                uj[i]=pref[i-k];

                pref[i]=(pref[i]+pref[i-k])%mod;
                /*pref[i]+=pref[i-k];
                if (pref[i]>=mod) pref[i]-=mod;*/
            }
        }
        sum+=k, k++;
        for (int i=0; i<=n; i++) {

            ans[i]=(ans[i]+uj[i])%mod;
            //ans[i]+=uj[i];
            //if (ans[i]>=mod) ans[i]-=mod;
            regi[i]=uj[i];
            uj[i]=0;
        }
    }
    for (int i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}