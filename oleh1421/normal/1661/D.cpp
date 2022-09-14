#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
mt19937 rnd(time(NULL));
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int N=600010;
ll b[N];
ll add[N];
void solve(){
    int n,k;cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>b[i];
    ll res=0ll;
    ll sum=0ll;
    ll sum1=0ll;
    for (int i=n;i>=k;i--){
        sum-=i*add[i];
        sum1-=add[i];
        b[i]=b[i]-i*sum1+sum;
        ll cur=(b[i]+k-1)/k;
        cur=max(cur,0ll);
        res+=cur;
        add[i-k]+=cur;
        sum+=(i-k)*cur;
        sum1+=cur;
    }
    ll mx=0ll;
    for (ll i=k-1;i>=1;i--){
        sum-=i*add[i];
        sum1-=add[i];
        b[i]=b[i]-i*sum1+sum;
        mx=max(mx,(b[i]+i-1)/i);
    }
    res+=mx;
    cout<<res<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }

    return 0;
}
/**
1000000000

3 4 8


3 12 24

19

**/