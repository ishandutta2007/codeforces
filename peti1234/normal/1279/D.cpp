#include <bits/stdc++.h>

using namespace std;
long long mod=998244353, res, f;
int db[1000001];
long long ans[1000001];
int n;
long long oszt(long long a)
{
    long long ans=1, p=mod-2;
    while(p) {
        if (p%2) ans*=a, ans%=mod;
        p/=2, a*=a, a%=mod;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        f=oszt(x);
        for (int j=1; j<=x; j++) {
            int a;
            cin >> a;
            db[a]++;
            ans[a]+=f;
            ans[a]%=mod;
        }
    }
    f=oszt(n);
    for (int i=1; i<=1000000; i++) {
        if (db[i]) {
            long long sum=f*db[i];
            sum%=mod;
            sum*=ans[i];
            sum%=mod;
            res+=sum;
            res%=mod;
        }
    }
    cout << (res*f)%mod << "\n";
    return 0;
}