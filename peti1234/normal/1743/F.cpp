#include <bits/stdc++.h>

using namespace std;
const int c=300005;
long long n, l[c], r[c], po2[c], po3[c], sum, mod=998244353;
set<int> s;
int main()
{
    cin >> n;
    po2[0]=1, po3[0]=1;
    for (int i=1; i<=n; i++) {
        po2[i]=po2[i-1]*2%mod;
        po3[i]=po3[i-1]*3%mod;
    }
    for (int i=1; i<=n; i++) {
        cin >> l[i] >> r[i];
    }
    for (int i=0; i<c; i++) {
        s.insert(i);
    }
    for (int i=n; i>=1; i--) {
        auto it=s.lower_bound(l[i]);
        while (*it<=r[i]) {
            if (i==1) {
                sum=(sum+po2[n-1])%mod;
            } else {
                sum=(sum+po3[i-2]*po2[n-i+1])%mod;
            }
            s.erase(*it);
            it=s.lower_bound(l[i]);
        }
    }
    cout << sum << endl;
    return 0;
}