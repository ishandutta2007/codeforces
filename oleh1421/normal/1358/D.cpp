//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
ll a[N];
ll f(ll x){
    return (x*(x+1ll))/2ll;
}
ll pref[N];
int n;
ll x;
ll get(ll x){
    int ind=upper_bound(a+1,a+n+n+1,x)-a-1;
    ll res=pref[ind]+f(x-a[ind]);
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>x;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=n+1;i<=n+n;i++) a[i]=a[i-n];
    for (int i=1;i<=n+n;i++){
        pref[i]=pref[i-1]+f(a[i]);
        a[i]+=a[i-1];
    }
    ll res=0ll;
    for (int i=1;i<=n;i++){
        res=max(res,get(a[i+n])-get(a[i+n]-x));
    }
    cout<<res<<endl;
    return 0;
}
/*
4
0100
1110
0101
0111
*/