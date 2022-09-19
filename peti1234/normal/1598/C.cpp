#include <bits/stdc++.h>

using namespace std;
long long w, n, sum, ert, dif, ans;
vector<long long> sz;
map<long long, long long> m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=0; i<n; i++) {
            int x;
            cin >> x;
            sz.push_back(x);
            sum+=x;
        }
        ert=sum;
        long long s=__gcd(n, n-2);
        if (ert%(n/s)) {
            cout << 0 << "\n";
        } else {
            ert/=(n/s);
            ert*=((n-2)/s);
            dif=sum-ert;
            for (auto x:sz) {
                ans+=m[dif-x];
                m[x]++;
            }
            cout << ans << "\n";
        }
        sum=ert=dif=ans=0;
        sz.clear(), m.clear();
    }
    return 0;
}