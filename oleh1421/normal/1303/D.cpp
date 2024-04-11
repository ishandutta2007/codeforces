#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=100010;
ll a[N];
ll cnt[30];
void solve(){
    for (int i=0;i<30;i++) cnt[i]=0;
    ll n;cin>>n;
    int m;cin>>m;
    ll sum=0ll;
    for (int i=1;i<=m;i++){
        cin>>a[i];
        sum+=a[i];
        int cur=0;
        while (a[i]>1){
            a[i]/=2;
            cur++;
        }
        cnt[cur]++;
        a[i]=(1ll<<cur);
    }
    if (sum<n){
        cout<<"-1\n";
        return;
    }
    ll res=0ll;
    for (int i=29;i>=1;i--){
        ll x=(n/(1ll<<i));
        x=min(x,cnt[i]*1ll);
        cnt[i]-=x;
        n-=(1ll<<i)*x;
        sum-=(1ll<<i)*x;
        ll y=(sum-n)/((1ll<<i));
        y=min(y,cnt[i]);
        cnt[i]-=y;
        sum-=(1ll<<i)*y;
        res+=cnt[i];
        cnt[i-1]+=cnt[i]*2;
        cnt[i]=0;

    }
    cout<<res<<endl;


}

int32_t main()
{
//    freopen("repair.in","r",stdin);
//    freopen("repair.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;

}