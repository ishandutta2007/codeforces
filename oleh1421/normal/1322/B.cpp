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
const int N=500010;
int a[N];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    int res=0;
    for (int i=25;i>=0;i--){
        for (int j=1;j<=n;j++){
            a[j]&=(2<<i)-1;
        }
        sort(a+1,a+n+1);
        int cnt=0;
        for (int j=1;j<=n;j++){
            if ((a[j]<<1)&(1<<i)) cnt--;
            cnt+=lower_bound(a+1,a+n+1,(2<<i)-a[j])-lower_bound(a+1,a+n+1,(1<<i)-a[j]);
//            if (lower_bound(a+1,a+n+1,(2<<i)-a[j])-lower_bound(a+1,a+n+1,(1<<i)-a[j])) cout<<"OK\n";
            cnt+=n+1-(lower_bound(a+1,a+n+1,(3<<i)-a[j])-a);
        }
//        if (cnt) cout<<i<<" "<<cnt<<" "<<a[1]<<" "<<a[2]<<endl;
        if (cnt%4) res^=(1<<i);

    }
    cout<<res;
    return 0;
}