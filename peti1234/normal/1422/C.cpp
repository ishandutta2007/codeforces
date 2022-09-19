#include <bits/stdc++.h>

using namespace std;
long long mod=1e9+7, sum, db, n, po=1, x;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> s;
    n=s.size();
    for (int i=0; i<n; i++) db+=s[i]-'0';
    for (long long i=n-1; i>=0; i--) {
        x=s[i]-'0';
        db-=x;
        sum+=db*(n-i)%mod*po%mod;
        sum+=x*i*(i+1)/2%mod*po%mod, sum%=mod;
        po*=10, po%=mod;
    }
    cout << sum << "\n";
    return 0;
}