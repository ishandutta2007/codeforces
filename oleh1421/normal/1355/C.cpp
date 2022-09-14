#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const ll mod=1000000000;
const int N=300010;
int a[N];
int dp[N];
void solve(){
    ll a,b,c,d;cin>>a>>b>>c>>d;
    ll res=0ll;
    for (ll z=c;z<=d;z++){
        ll L=z+1-b;
        ll R=min(z+1-a,c);

        if (L<b){
            if (b<=R) res+=(b-L)*(c-b+1ll);
            else res+=(R-L+1ll)*(c-b+1ll);
        }
        L=max(L,b);

        if (L>R) continue;
        res+=(R-L+1ll)*(c+1ll);
        res-=(R+L)*(R-L+1ll)/2ll;


    }
    cout<<res<<endl;
}
int main()
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