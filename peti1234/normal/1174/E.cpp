#include <bits/stdc++.h>

using namespace std;
long long mod=1000000007;
int dp[1000001][22][2];
long long n;
long long solve(long long a, long long b, long long c)
{
    //cout << a << " " << b << " " << c << endl;
    if (a==n) {
        if (b==0 && c==0) {
            return 1;
        }
        return 0;
    }
    if (dp[a][b][c]!=0) {
        return dp[a][b][c];
    }
    long long ans=0;
    if (c==0) {
        long long ert=(1<<b);
        long long d=n/ert;
        //cout << d << " " << ert << endl;
        if (d>a) {
        ans+=(d-a)*solve(a+1, b, c);
        }
        ans%=mod;
        if (b>0) {
            ert=n/(1<<(b-1));
            ert-=d;
            if (ert>0) {
            ans+=ert*solve(a+1, b-1, c);
            }
            ans%=mod;
        }
        dp[a][b][c]=ans;
        return ans;
    } else {
        long long ert=(1<<b);
        ert*=3;
        long long d=n/ert;
        if (d>a) {
        ans+=(d-a)*solve(a+1, b, c);
        }
        ans%=mod;
        if (b>0) {
            ert=(1<<(b-1))*3;
            ert=n/ert;
            ert-=d;
            if (ert>0){
            ans+=ert*solve(a+1, b-1, c);
            }
            ans%=mod;
        }
        ert=(1<<b);
        ert=n/ert;
        if (ert>d) {
        ans+=(ert-d)*solve(a+1, b, 0);
        }
        ans%=mod;
        dp[a][b][c]=ans;
        return ans;
    }

}
long long db=0;
int main()
{
    cin >> n;
    long long a=1;
    while(2*a<=n) {
        a*=2;
        db++;
    }
    for (int i=n; i>=1; i--) {
        for (int j=0; j<15; j++) {
            solve(i, j, 0);
            solve(i, j, 1);
        }
    }
    long long sum=solve(1, db, 0);
    if (a/2*3<=n) {
        sum+=solve(1, db-1, 1);
    }
    cout << sum%mod << endl;
    return 0;
}