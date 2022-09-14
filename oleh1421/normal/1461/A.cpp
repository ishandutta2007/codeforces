#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=300010;
const ll mod=998244353;
void solve(){
    int n,k;cin>>n>>k;
    for (int i=0;i<n;i++){
        cout<<char('a'+i%3);
    }
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