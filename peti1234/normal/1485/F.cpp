#include <bits/stdc++.h>

using namespace std;
const int c=200002;
long long w, n, t[c], kom[c], mod=1e9+7, sum;
map<long long, long long> m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        m.clear(), sum=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            kom[i]=kom[i-1]+t[i];
        }
        m[0]=1, sum=1;
        for (int i=1; i<n; i++) {
            long long ert=sum-m[kom[i]]+mod;
            m[kom[i]]+=ert;
            m[kom[i]]%=mod;
            sum+=ert;
            sum%=mod;
        }
        cout << sum << "\n";
    }
    return 0;
}