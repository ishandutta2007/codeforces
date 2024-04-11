//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
//#define int long long
#define checkmin(a,b) if (a>b) a=b;
#define checkmax(a,b) if (a<b) a=b;
typedef long long ll;
using namespace std;
int a[1001];
int cnt[1001];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    int x=n/2+n%2;
    for (int i=1;i<=n;i++) cnt[a[i]]++;
    int cur=0;
    for (int i=1;i<=k;i++){
        cur+=cnt[i]/2;
    }
    cout<<x+cur;
    return 0;
}