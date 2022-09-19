#include <bits/stdc++.h>
 
using namespace std;
long long n;
long long mod=998244353;
vector<long long> sz[200001];
long long f[200001];
bool v[200001];
long long solve(long long a)
{
    v[a]=true;
    long long ans=1;
    for (long long i=0; i<sz[a].size(); i++) {
        long long x=sz[a][i];
        if (!v[x]) {
            ans*=solve(x);
            ans%=mod;
        }
    }
    ans*=f[sz[a].size()];
    ans%=mod;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    f[0]=1;
    for (long long i=1; i<n; i++) {
        f[i]=f[i-1]*i;
        f[i]%=mod;
        long long a, b;
        cin >> a >> b;
        sz[a].push_back(b);
        sz[b].push_back(a);
    }
    f[n]=f[n-1]*n;
    f[n]%=mod;
    cout << (solve(1)*n)%mod;
    return 0;
}