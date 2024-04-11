//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define int long long
#define checkmin(a,b) if (a>b) a=b;
#define checkmax(a,b) if (a<b) a=b;
typedef long long ll;
using namespace std;
int a[100001];
int b[100001];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    int maxx0=a[1];
    int maxx1=b[1];
    for (int i=2;i<=n;i++){
        int cur0=maxx1+a[i];
        int cur1=maxx0+b[i];
        maxx0=max(maxx0,cur0);
        maxx1=max(maxx1,cur1);
    }
    cout<<max(maxx0,maxx1);
    return 0;
}