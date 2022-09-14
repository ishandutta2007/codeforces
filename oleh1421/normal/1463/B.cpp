
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=500010;
const ll mod=1000000007ll;
int a[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        int cur=1;
        while (cur*2<=x) cur*=2;
        a[i]=cur;
    }
    for (int i=1;i<=n;i++) cout<<a[i]<<" ";
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
//3 1 5 4 2 2
//3 1 1