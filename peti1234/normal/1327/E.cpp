#include <bits/stdc++.h>

using namespace std;
long long n, mod=998244353;
long long hat[200001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    hat[0]=1;
    for (int i=1; i<=n; i++) {
        hat[i]=(hat[i-1]*10)%mod;
    }
    for (int i=1; i<=n; i++) {
        if (i==n) {
            cout << 10 << endl;
            return 0;
        }
        long long ans=(2*9*hat[n-i-1])%mod;
        ans+=(n-1-i)*81*hat[n-i-2]%mod;
        cout << (10*ans)%mod << " ";
    }
    return 0;
}