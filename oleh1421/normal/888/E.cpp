//#pragma GCC opitmize ("trapv")
//#pragma GCC optimize ("Ofast")
//#pragma GCC optimize ("unroll-loops")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
template<class T>using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll mod=1000000007ll;
int a[40];
vector<int>get(int l,int r,int m){
    int len=r-l+1;
    vector<int>v;
    for (int mask=0;mask<(1<<len);mask++){
        ll sum=0ll;
        for (int i=0;i<len;i++){
            if (mask&(1<<i)){
                sum+=a[l+i];
            }
        }
        sum%=m;
        v.push_back(sum);
    }
    sort(v.begin(),v.end());
    return v;
}
int32_t main()
{
//    freopen("landscape.in","r",stdin);
//    freopen("landscape.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    ll m;cin>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    vector<int>v=get(1,n/2,m);
    vector<int>u=get(n/2+1,n,m);
    int res=(v.back()+u.back())%m;
    reverse(v.begin(),v.end());
    int j=-1;
    for (int i=0;i<v.size();i++){
        while (j+1<u.size() && u[j+1]+v[i]<m) j++;
        if (j!=-1) res=max(res,u[j]+v[i]);
    }
    cout<<res;
    return 0;
}