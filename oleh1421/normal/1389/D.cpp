#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=300010;
void solve(){
    ll n,k;cin>>n>>k;
    int l1,r1,l2,r2;cin>>l1>>r1>>l2>>r2;
    if (l1>l2){
        swap(l1,l2);
        swap(r1,r2);
    }
    if (r1>=r2){
        k=max(0ll,k-(r2-l2)*n);
        if (n*(r1-r2-l1+l2)>=k) cout<<k<<endl;
        else cout<<k+k-n*(r1-r2-l1+l2)<<endl;
    } else if (r1>=l2){
        k=max(0ll,k-(r1-l2)*n);
        ll add=r2-r1+l2-l1;
        if (n*add>=k) cout<<k<<endl;
        else cout<<k+k-n*add<<endl;
    } else {
//        cout<<"OK\n";
        ll res=100000000000000001ll;
        for (ll i=1;i<=n;i++){
            ll opp=(l2-r1)*i;
            ll add=(r2-l1);
            if (i*add>=k) {
                res=min(res,opp+k);
            }
            else {
                res=min(res,opp+k+k-i*add);
            }
//            if (res==6) cout<<i<<endl;
        }
        cout<<res<<endl;
    }
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
5 4 2
4 5
1 1 1 1 1
1 1 5 5

1 2
1 3
3 4
3 5

*/