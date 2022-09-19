#include <bits/stdc++.h>

using namespace std;
const int c=25;
long long n, db[c], sum[c][c], po[c], ans, mod=998244353;
int main()
{
    ios_base::sync_with_stdio(false);
    po[0]=1;
    for (int i=1; i<c; i++) po[i]=po[i-1]*10%mod;
    cin >> n;
    for (int i=1; i<=n; i++) {
        long long x;
        cin >> x;
        long long xx=x, cnt=0, cnt2=0;
        while (xx) {
            xx/=10;
            cnt++;
        }
        db[cnt]++;
        while (x) {
            sum[cnt][cnt2]+=x%10;
            x/=10;
            cnt2++;
        }
    }

    for (int kezd=1; kezd<=10; kezd++) {
        for (int veg=1; veg<=10; veg++) {
            int s=min(kezd, veg);
            vector<int> sz;
            for (int i=0; i<min(kezd, veg); i++) {
                sz.push_back(1);
                sz.push_back(0);
            }
            for (int i=0; i<kezd-s; i++) {
                sz.push_back(0);
            }
            for (int i=0; i<veg-s; i++) {
                sz.push_back(1);
            }
            int k1=0, v1=0;
            for (int i=0; i<kezd+veg; i++) {
                if (sz[i]==0) {
                    ans=(ans+po[i]*db[veg]%mod*sum[kezd][k1]%mod)%mod;
                    k1++;
                }
                if (sz[i]==1) {
                    ans=(ans+po[i]*db[kezd]%mod*sum[veg][v1]%mod)%mod;
                    v1++;
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}