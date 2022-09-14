#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
//#define inf 1000000000000000001ll
int a[100001];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    ll sum=0ll;
    for (int i=1;i<=n;i++) cin>>a[i],sum+=a[i]*1ll;
    sort(a+1,a+n+1);
    ll sum1=0ll;
    for (int i=1;i<=n/2;i++){
        sum1+=a[i];
    }
    cout<<(sum-sum1)*(sum-sum1)+sum1*sum1;
    return 0;
}
/*

*/