#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[500001];
ll cnt[3];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;cin>>n;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        if (x<0) a[i]=1;
        else a[i]=0;
    }
    cnt[0]=1;
    ll x=0ll;
    int sum=0;
    for (int i=1;i<=n;i++){
        sum^=a[i];
        x+=cnt[sum]*1ll;
        cnt[sum]++;
    }
    cout<<(n*(n+1ll)/2ll)-x<<" "<<x;
    return 0;
}