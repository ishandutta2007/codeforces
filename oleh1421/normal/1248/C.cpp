#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
ll f[200001];
const ll mod=1000000007ll;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    f[0]=1ll;
    f[1]=1ll;
    for (int i=2;i<=100000;i++) f[i]=(f[i-1]+f[i-2])%mod;
    int n,m;cin>>n>>m;
    cout<<((f[n]+f[m]-1ll)*2ll)%mod;
    return 0;
}
/*
3 4 2
.*.*
.#.*
.*#*
*/