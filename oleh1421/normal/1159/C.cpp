#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll b[100001];
ll g[100001];
int main()
{
    ll n,m;cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>b[i];
    }
    for (int i=1;i<=m;i++) {
        cin>>g[i];
    }
    sort(b+1,b+n+1);
    sort(g+1,g+m+1);
    if (b[n]>g[1]){
        cout<<-1;
        return 0;
    }

    ll res=0ll;
    for (int i=1;i<=n;i++){
        res+=1ll*m*b[i]*1ll;
    }
    if (b[n]==g[1]){
        res-=1ll*m*b[n]*1ll;
    } else {
        res-=(m-1ll)*b[n]*1ll;
        res-=1ll*b[n-1]*1ll;
    }
    for (int i=1;i<=m;i++){
        res+=1ll*g[i]*1ll;
    }
    cout<<res;
    return 0;
}