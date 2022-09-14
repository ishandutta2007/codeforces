#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int N=100010;
int r[N];
int b[N];
int main()
{
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>r[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    int cnt1=0;
    int cnt2=0;
    for (int i=1;i<=n;i++){
        if (r[i]-b[i]>0) cnt1++;
        else if (r[i]-b[i]<0) cnt2++;
    }
    if (cnt1==0){
        cout<<-1;
        return 0;
    }
    cout<<cnt2/cnt1+1;
    return 0;
}