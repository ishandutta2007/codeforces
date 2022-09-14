//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define int ll
#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const int N=1000010;
const ll mod=1000000007;
ll a[N];
ll b[N];
void solve(){
    int n,k;cin>>n>>k;
    k++;
    for (int i=1;i<=n;i++) cin>>a[i];
    ll sum=0ll;
    for (int i=1;i<n;i++){
        b[i]=1;
        for (int j=1;j<=a[i+1]-a[i];j++) b[i]*=10;
        b[i]--;
        sum+=b[i];
    }
    b[n]=0;
    ll pw=1;
    for (int i=1;i<=a[n];i++) pw*=10;
    ll ans=0ll;
    for (int i=n;i>=1;i--){
        sum-=b[i];
//        cout<<i<<" "<<k<<" "<<sum<<endl;
        ll cur=max(0ll,k-sum);
        ans+=pw*cur;
        k-=cur;
        for (int j=a[i-1];j<a[i];j++) pw/=10ll;

    }
//    cout<<k<<" ";
    cout<<ans<<endl;


}
int32_t  main()
{
//    cout<<mod<<endl;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
//6 3 7 5 6
/**
7 1 2
2 15 6 3 7 5 6
3 5
1
**/