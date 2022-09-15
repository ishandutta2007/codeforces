#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s[3000001];
ll a[3000001];
int main()
{
    ll n,k;cin>>n>>k;
    for (ll i=1;i<=n;i++) cin>>a[i];
    reverse(a+1,a+n+1);
    for (ll i=1;i<=n;i++) {
         s[i]=s[i-1]+a[i]*1ll;
    }
    ll res=0ll;
    res+=s[n];
    sort(s+1,s+n);
    /*for (int i=1;i<=n;i++) cout<<s[i]<<" ";
    cout<<endl;*/
    reverse(s+1,s+n);
    /*for (int i=1;i<=n;i++) cout<<s[i]<<" ";
    cout<<endl;*/
    for (int i=1;i<k;i++) res+=s[i];
    cout<<res;
    return 0;
}