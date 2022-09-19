#include <bits/stdc++.h>

using namespace std;
long long mod=1000000007, n, m, sum=1;
long long h(long long a, long long b) {
    long long ans=1;
    long long p=a;
    while(b>0) {
        if (b%2) {
            ans*=p;
            ans%=mod;
        }
        p*=p;
        p%=mod;
        b/=2;
    }
    return ans;
}
long long pl(long long a, long long b)
{
    long long sum=0;
    while(b>0) {
        sum+=b/a;
        b/=a;
    }
    sum%=(mod-1);
    return h(a, sum);
}
int main()
{
    cin >> n >> m;
    for (int i=2; i*i<=n; i++) {
        int db=0;
        while (!(n%i)) {
            db++;
            if (db==1) {
                sum*=pl(i, m);
                sum%=mod;
            }
            n/=i;
        }
    }
    if (n!=1) {
        sum*=pl(n, m);
        sum%=mod;
    }
    cout << sum << endl;
    return 0;

}