#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, phi[c];
long long sum, mod=1e9+7;
vector<int> oszt[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (long long i=1; i<=n; i++) {
        phi[i]+=i;
        for (int j=2*i; j<=n; j+=i) {
            phi[j]-=phi[i];
        }
        if (i>1) {
            for (long long s=1; s*i<n; s++) {
                long long rem=n-s*i;
                sum=(sum+rem*s*phi[i]/__gcd(s, rem))%mod;
            }
        }
        //cout << i << " " << phi[i] << "\n";
    }
    cout << sum << "\n";
    return 0;
}