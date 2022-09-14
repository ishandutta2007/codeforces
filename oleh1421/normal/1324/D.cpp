#include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
//#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int N=200010;
int a[N];
map<int,int>mp;
int bit[N];

int main()
{
//    freopen("three.in","r",stdin);
//    freopen("three.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) {
        int x;cin>>x;
        a[i]-=x;
    }
//    set<int>st;
//    for (int i=1;i<=n;i++) st.insert(a[i]);
//    int cnt=0;
//    for (auto i:st){
//        mp[i]=++cnt;
//    }
//    for (int i=1;i<=n;i++) a[i]=mp[a[i]],cout<<a[i]<<" ";
//    cout<<endl;
    ll res=0ll;
    ordered_set st;
    for (int i=1;i<=n;i++){
        res+=i-1ll;
        res-=st.order_of_key(-a[i]+1);
        st.insert(a[i]);
    }
    cout<<res;
    return 0;
}