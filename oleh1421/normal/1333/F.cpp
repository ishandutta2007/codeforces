#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int N=500010;
int mx[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        for (int j=i+i;j<=n;j+=i) mx[j]=max(mx[j],i);
    }
    sort(mx+1,mx+n+1);
    for (int i=2;i<=n;i++) cout<<mx[i]<<" ";
    return 0;
}