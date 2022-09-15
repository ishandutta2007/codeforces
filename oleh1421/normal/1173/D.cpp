#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll d[300001];
ll f[300001];
const long long mod=998244353ll;
int main()
{
    int n;cin>>n;
    for (int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        d[u]++;
        d[v]++;
    }
    f[0]=1ll;
    for (int i=1;i<=n;i++) f[i]=(f[i-1]*1ll*i*1ll)%mod;
    ll res=n*1ll;
    for (int i=1;i<=n;i++) res=(res*f[d[i]])%mod;
    cout<<res;
    return 0;
}
//1-0
//3-1
//5-2
//7 3
//9 4