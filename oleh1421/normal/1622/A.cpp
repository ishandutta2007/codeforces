#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
//#define int ll
using namespace std;
const int N=300010;
const ll mod=998244353;
int a[3];
void solve(){
    for (int i=0;i<3;i++) cin>>a[i];
    for (int i=0;i<3;i++){
        if (a[i]==a[(i+1)%3]+a[(i+2)%3] || (a[(i+1)%3]==a[(i+2)%3] && a[i]%2==0)){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";

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
/**




**/