#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T>using ordered_set=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
typedef long long ll;
#define endl '\n'
const int N=400010;
const ll mod=1000000007;
int a[N];
void solve(){
    int n;cin>>n;
    int pos=n+1;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        if (x==1 && pos==n+1) pos=i;
    }
    for (int i=1;i<pos;i++) cout<<i<<" ";
    cout<<n+1<<" ";
    for (int i=pos;i<=n;i++) cout<<i<<" ";
    cout<<endl;


}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/*
ba
ca
aca
a
b
c
ac
*/