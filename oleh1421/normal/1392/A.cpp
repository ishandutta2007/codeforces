#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200100;
const ll mod=998244353;
int a[N];
void solve(){
    int n;cin>>n;
    bool ok=false;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        ok|=(a[1]!=a[i]);
    }
    if (ok) cout<<1<<endl;
    else cout<<n<<endl;

}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}