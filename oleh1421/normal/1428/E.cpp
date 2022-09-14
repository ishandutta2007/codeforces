#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
#define y1 y_1
const int N=500010;
ll a[N];
ll cnt[N];
ll del[N];
ll f(ll x,ll y){
    return ((x/y)*(x/y))*(y-x%y)+((x/y+1ll)*((x/y+1ll))*(x%y));
}
void solve(){
    ll n,k;cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    vector<ll>v;
    int tot=0;
    ll res=0ll;
    for (int i=1;i<=n;i++){
        int R=min((k/i),a[i]);
        tot+=R;
        res+=f(a[i],R);
        for (int j=R-1;j>=1;j--){
            v.push_back(f(a[i],j)-f(a[i],j+1));
        }
    }
//    cout<<res<<endl;

    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    while (tot>k){
        tot--;
        res+=v.back();
        v.pop_back();
    }
    cout<<res<<endl;
}
int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
//    int x,k;cin>>x>>k;
//    for (int i=2;i<=k;i++){
//        cout<<f(x,i-1)-f(x,i)<<endl;
//    }
    return 0;
}