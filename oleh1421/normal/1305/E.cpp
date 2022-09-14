#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
///#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int N=10000;
int a[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    int m;cin>>m;
    if (n<=2){
        if (m==0){
            for (int i=1;i<=n;i++) cout<<i<<" ";
            return 0;
        }
        cout<<-1;
        return 0;
    }
    int k=0;
    for (int i=1;i<=1000000000;i++){
        if (m<(i-1)/2) break;
        m-=(i-1)/2;
        k++;
    }
    if (k>n || (k==n && m>0)){
        cout<<-1;
        return 0;
    }
    for (int i=1;i<=k;i++) a[i]=i;
    a[k+1]=k+1;
    a[k+1]+=(k/2-m)*2;
    for (int i=n;i>k+1;i--) a[i]=1000000000-N*(n-i);
    for (int i=1;i<=n;i++) cout<<a[i]<<" ";
    return 0;
}