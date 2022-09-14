#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const long long mod=1000000007LL;
int a[300001];
ll mask[300001];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    ll start_sum=0ll;
    for (int i=1;i<=n;i++) cin>>a[i]>>mask[i],start_sum+=a[i]*1ll;
    ll res=0ll;
    for (int i=0;i<=60;i++){
        ll sum=0ll;
        for (int j=1;j<=n;j++){
            if (mask[j]>=(1ll<<i) && mask[j]<(1ll<<(i+1))) sum+=a[j]*1ll;
        }
        if ((sum>0 && start_sum>0)||(sum<0 && start_sum<0)){
            res^=(1ll<<i);
            for (int j=1;j<=n;j++){
                if (mask[j]&(1ll<<i)) a[j]=-a[j];
            }
        }
    }
    cout<<res;
    return 0;
}