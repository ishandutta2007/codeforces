//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
const int A=1000001;
const ll mod=1000000007ll;
ll pref[N];
ll mx[N];
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>pref[i],pref[i]+=pref[i-1],mx[i]=max(mx[i-1],pref[i]);
    for (int i=1;i<=m;i++){
        ll x;cin>>x;
        int pos=lower_bound(mx+1,mx+n+1,x)-mx;
        if (pos<=n){
            cout<<pos-1<<" ";
            continue;
        }
        if (pref[n]<=0){
            cout<<-1<<" ";
            continue;
        }
        ll it=(x-mx[n]+pref[n]-1)/pref[n];
        x-=pref[n]*it;
        pos=lower_bound(mx+1,mx+n+1,x)-mx;
        cout<<pos+it*n-1<<" ";

    }
    cout<<endl;


}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;

    while (tt--){
        solve();
    }
    return 0;
}
/*
1
3 3
1 -3 4
1 5 2
*/