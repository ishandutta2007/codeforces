#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=100010;
const ll mod=1000000007ll;

void solve(){
    ll l,r,m;cin>>l>>r>>m;

    for (ll a=l;a<=r;a++){
        ll k=m%a;
        ll k1=(a-k)%a;
        ll b,c;
        if (l+k1<=r){
            c=l+k1;
            b=l;
            cout<<a<<" "<<b<<" "<<c<<endl;
            return;
        }
        if (l+k<=r){

            if (l+a-k<=r){
                cout<<a<<" "<<l<<" "<<l+a-k<<endl;
            } else if (m-k>=a){
                cout<<a<<" "<<l+k<<" "<<l<<endl;
            }

            return;
        }

    }
}
int main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}