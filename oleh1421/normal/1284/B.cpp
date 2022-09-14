//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
///use char if you want a naive algorithm to pass
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
const int N=200001;
int minx[N];
int maxx[N];
bool ok[N];
int a[1000011];
int s[1000011];
void solve(){
    ll n;cin>>n;
    for (int i=1;i<=n;i++){
        int k;cin>>k;
        int x;cin>>x;
        minx[i]=x;
        maxx[i]=x;
        for (int j=2;j<=k;j++){
            int x;cin>>x;
            if (x>minx[i]) ok[i]=true;
            minx[i]=min(minx[i],x);
            maxx[i]=max(maxx[i],x);
        }
    }
    for (int i=1;i<=n;i++){
        if (ok[i]) continue;
        a[maxx[i]]++;
    }
    s[0]=a[0];
    for (int i=1;i<=1000000;i++) s[i]=s[i-1]+a[i];
    ll res=n*1ll*n*1ll;
    for (int i=1;i<=n;i++){
        if (ok[i]) continue;
        res-=s[minx[i]]*1ll;
        //res+=(minx[i]==maxx[i]);
    }
    cout<<res<<endl;


}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}