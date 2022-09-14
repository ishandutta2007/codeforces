#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
const int N=2000010;
const ll mod=1000000007;
const int L=20;
const ll inv2=(mod+1)/2;
ll a[N];
int n;
ll f(ll t){
    ll res=(a[1]+a[n])*t+a[1]*a[n];
    for (int i=2;i<n;i++) res+=min(a[1]*a[i]+a[1]*t+a[i]*t,a[n]*a[i]+a[n]*t+a[i]*t);
    return res;
}
void solve(){
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
//    for (int t=-10;t<=10;t++){
//        cout<<t<<" "<<f(t)<<endl;
//    }
    ll sum=0ll;
    for (int i=1;i<=n;i++) sum+=a[i];
    if (a[1]*(n-2ll)+sum>0 || a[n]*(n-2ll)+sum<0){
        cout<<"INF\n";
        return;
    }
    ll t=-1e6-1;
    for (int i=21;i>=0;i--){
        if (f(t+(1<<i))<f(t+(1<<i)+1)) t+=(1<<i);
    }
    cout<<f(t+1)<<endl;

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


//2
//
//1 2

/**
3
3 -1 -2


**/