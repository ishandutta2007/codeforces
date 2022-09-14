#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=100010;
void solve(){
    ll k,l,r,t,x,y;cin>>k>>l>>r>>t>>x>>y;
    r-=l;
    k-=l;
    if (y<=x){
        if (k+y>r){
            if (k<x){
                cout<<"No\n";
                return;
            }
            k-=x;
            t--;
        }
        if ((x-y)<=k/t){
            cout<<"Yes\n";
        } else {
            cout<<"No\n";
        }
        return;
    }
    if (x+y<=r){
        cout<<"Yes\n";
        return;
    }
    ll cnt=0;
    for (ll it=1;it<=t;it++){
        if (k>=x) {
            it+=k/x-1;
            k%=x;
            cnt++;
//            k-=x;
        } else if (k+y<=r){
//            k+=y-x;
            ll cur=(r-k-y)/(y-x);
            k+=(cur+1ll)*(y-x);
            it+=cur;
        }
        else {
            cout<<"No\n";
            return;
        }
        if (cnt>x+2) break;
    }
    cout<<"Yes\n";

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }

    return 0;
}
//3 1 5 4 2 2