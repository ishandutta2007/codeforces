#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long n, k, fakt[c], inv[c], si[c], mod=1e9+7, ans;
vector<int> sz[c];
bool v[c];
long long oszt(long long a) {
    long long ans=1, p=mod-2;
    while (p) {
        if (p%2) {
            ans=ans*a%mod;
        }
        a=a*a%mod;
        p/=2;
    }
    return ans;
}
long long alatt(long long a, long long b) {
    if (a<b || b<0) return 0;
    return fakt[a]*inv[b]%mod*inv[a-b]%mod;
}
void dfs(int a) {
    si[a]=1, v[a]=true;
    long long spec=0, fel=0;
    for (auto x:sz[a]) {
        if (!v[x]) {
            dfs(x);
            long long ert=si[x];
            si[a]+=ert;
            spec+=si[x]*si[x];
            ans=(ans+alatt(ert, k)*(2*n-2*ert-1))%mod;
        } else {
            fel=x;
        }
    }
    spec+=(n-si[a])*(n-si[a]);
    ans=(ans+alatt(n-si[a], k)*(2*si[a]-1))%mod;
    for (auto x:sz[a]) {
        long long ert=(x!=fel ? si[x] : n-si[a]);
        ans=(ans+alatt(ert, k)*(((n-1-ert)*(n-1-ert)-spec+ert*ert)%mod))%mod;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    fakt[0]=1, inv[0]=1;
    for (int i=1; i<=n; i++) {
        fakt[i]=fakt[i-1]*i%mod;
        inv[i]=oszt(fakt[i]);
    }
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    dfs(1);
    cout << (n*alatt(n, k)%mod*n%mod-ans+mod)%mod << "\n";
    return 0;
}