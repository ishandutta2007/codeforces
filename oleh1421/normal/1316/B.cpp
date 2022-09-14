#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
///#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int N=500050;
//int a[N];
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    string mins=s;
    int k=1;
    for (int i=2;i<=n;i++){
        string cur="";
        for (int j=i-1;j<n;j++) cur+=s[j];
        if ((n-i+1)%2){
            for (int j=i-2;j>=0;j--) cur+=s[j];
        } else {
            for (int j=0;j<=i-2;j++) cur+=s[j];
        }
//        cout<<i<<" "<<cur<<endl;
        if (mins>cur){
            k=i;
            mins=cur;
        }
    }
    cout<<mins<<endl;
    cout<<k<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}