#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const long long mod=1000000007LL;
int a[200001];
int b[200001];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    ll sum=0ll;
    int cnt0=0;
    int cnt=0;
    for (int i=1;i<=n;i++){
        sum+=abs(a[i]-1)*1ll;
        cnt0+=(a[i]==0);
        cnt+=(a[i]<0);
    }
    if (cnt0==0 && cnt%2) cnt--;
    sum-=2*cnt;
    cout<<sum;
    return 0;
}