#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int N=500010;
ll m[N];
ll pref[N];
ll suf[N];
ll f[N];
int l[N];
int r[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>m[i];
    for (int i=1;i<=n;i++){
        l[i]=0;
        for (int j=i-1;j>0;j=l[j]){
            if (m[j]<m[i]){
                l[i]=j;
                break;
            }
        }
    }
    for (int i=n;i>=1;i--){
        r[i]=n+1;
        for (int j=i+1;i<=n;j=r[j]){
            if (m[j]<m[i]){
                r[i]=j;
                break;
            }
        }
    }
    for (int i=1;i<=n;i++){
        pref[i]=(i-l[i]+0ll)*m[i]+pref[l[i]];
    }
    for (int i=n;i>=1;i--){
        suf[i]=(r[i]-i+0ll)*m[i]+suf[r[i]];
    }
    for (int i=1;i<=n;i++){
        f[i]=suf[i]+pref[i]-m[i]+0ll;
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