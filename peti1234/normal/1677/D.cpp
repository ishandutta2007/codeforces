#include <bits/stdc++.h>

using namespace std;
long long w, n, k, sum, mod=998244353;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k;
        sum=1;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            if (i<=k) sum=sum*i%mod;
            if (i>n-k && x>0) sum=0;
            if (i<=n-k) {
                if (x==-1) sum=sum*(i+k)%mod;
                if (x==0) sum=sum*(k+1)%mod;
            }
        }
        cout << sum << "\n";
    }
    return 0;
}