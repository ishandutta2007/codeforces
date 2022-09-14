#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=300020;
int a[N];
void solve(){
    int n;cin>>n;
    if (n%4){
        cout<<"NO\n";
        return;
    }
    a[1]=1;
    for (int i=2;i<=n/2;i++){
        a[i]=a[i-1]+4;
    }
    for (int i=1;i<=n/2;i++){
        if (i%2) a[i+n/2]=a[i]+1;
        else a[i+n/2]=a[i]-1;
    }
    for (int i=1;i<=n/2;i++){
        swap(a[i],a[i+n/2]);
    }
    cout<<"YES\n";
    for (int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}