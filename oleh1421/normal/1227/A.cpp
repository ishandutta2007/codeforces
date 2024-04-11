//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
//#define int long long
#define endl '\n'
typedef long long ll;
using namespace std;

void solve(){
    int n;cin>>n;
    int L,R;
    R=1000000001;
    L=-1000000001;
    for (int i=1;i<=n;i++){
        int l,r;cin>>l>>r;
        R=min(R,r);
        L=max(L,l);
    }
    cout<<max(L-R,0)<<endl;
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