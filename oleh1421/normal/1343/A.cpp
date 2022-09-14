#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
void solve(){
    int n;cin>>n;
    for (int i=2;i<=30;i++){
        ll y=(1<<i)-1;
        if (n%y==0){
            cout<<n/y<<endl;
            return;
        }
    }
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