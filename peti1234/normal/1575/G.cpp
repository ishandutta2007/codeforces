#include <bits/stdc++.h>

using namespace std;
const int c=100005;
long long n, ans, t[c], f[c], cnt[c], mod=1e9+7;
vector<int> oszt[c];
int main()
{
    for (int i=1; i<c; i++) {
        for (int j=i; j<c; j+=i) {
            oszt[j].push_back(i);
        }
    }
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<c; i++) {
        f[i]=i;
        for (auto x:oszt[i]) {
            if (x!=i) {
                f[i]-=f[x];
            }
        }
    }
    for (int p=1; p<=n; p++) {
        for (int i=p; i<=n; i+=p) {
            for (auto x:oszt[t[i]]) {
                cnt[x]++;
                //cout << "fontos " << p << " " << x << " " << f[p] << " " << f[x] << "\n";
                ans+=f[p]*f[x]*(2*cnt[x]-1)%mod;
            }
        }
        for (int i=p; i<=n; i+=p) {
            for (auto x:oszt[t[i]]) {
                cnt[x]--;
            }
        }
    }

    cout << ans%mod << "\n";
    return 0;
}