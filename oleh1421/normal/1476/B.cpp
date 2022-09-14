//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=301019;
const ll mod=1000000007ll;
ll p[N];
void solve(){
    ll n,k;cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>p[i];
    ll res=0ll;
    ll sum=p[1];
    for (int i=2;i<=n;i++){
//        cout<<i<<" "<<max(0ll,p[i]*100ll-sum*k+k-1ll)/k<<endl;
        res=max(res,max(0ll,p[i]*100ll-sum*k+k-1ll)/k);
        sum+=p[i];
    }
    cout<<res<<endl;
//    20199

}
int main()
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

*/