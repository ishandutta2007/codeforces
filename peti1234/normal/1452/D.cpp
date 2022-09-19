#include <bits/stdc++.h>

using namespace std;
const int c=200002;
long long mod=998244353, p=499122177;
long long n, fib[c], ans;
int main()
{
    cin >> n;
    fib[1]=1, fib[2]=1;
    for (int i=3; i<=n; i++) {
        fib[i]=(fib[i-1]+fib[i-2])%mod;
    }
    ans=fib[n];
    for (int i=1; i<=n; i++) {
        ans*=p;
        ans%=mod;
    }
    cout << ans << "\n";
    return 0;
}