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
    int m;cin>>m;
    for (int i=1;i<=m;i++) cin>>b[i];
    int maxA=0;
    int maxB=0;
    for (int i=1;i<=n;i++) maxA=max(maxA,a[i]);
    for (int i=1;i<=m;i++) maxB=max(maxB,b[i]);
    cout<<maxA<<" "<<maxB;
    return 0;
}