#include <bits/stdc++.h>

using namespace std;
long long mod=1e9+7, fib[100005], ans=1;
int n, db;
string s;
int main()
{
    cin >> s;
    n=s.size();
    fib[0]=fib[1]=1;
    for (int i=2; i<=n; i++) {
        fib[i]=(fib[i-1]+fib[i-2])%mod;
    }
    for (int i=0; i<n; i++) {
        if (s[i]=='m' || s[i]=='w') {
            ans=0;
        }
        if (i>0 && s[i]!=s[i-1]) {
            ans*=fib[db];
            ans%=mod;
            db=0;
        }
        if (s[i]=='u' || s[i]=='n') {
            db++;
        }
    }
    ans*=fib[db];
    ans%=mod;
    cout << ans << "\n";
    return 0;
}