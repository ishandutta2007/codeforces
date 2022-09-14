#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
//#define int ll
using namespace std;
const int N=503000;
const ll mod=998244353;

void solve(){
    int n,s;cin>>n>>s;
    n=n-(n+1)/2+1;
    cout<<s/n<<endl;
}
int32_t main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}