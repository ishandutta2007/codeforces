#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int N=500010;
int m[N];
int pref[N];
int suf[N];
int a[N];
ll f[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>m[i];
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++) a[j]=m[j];
        for (int j=i-1;j>=1;j--) a[j]=min(a[j],a[j+1]);
        for (int j=i+1;j<=n;j++) a[j]=min(a[j],a[j-1]);
        for (int j=1;j<=n;j++) f[i]+=a[j];
    }
    int ind=1;
    for (int i=2;i<=n;i++){
        if (f[i]>f[ind]) ind=i;
    }
    for (int i=ind-1;i>=1;i--) m[i]=min(m[i],m[i+1]);
    for (int i=ind+1;i<=n;i++) m[i]=min(m[i],m[i-1]);
    for (int i=1;i<=n;i++) cout<<m[i]<<" ";
    return 0;
}