#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200100;
const ll inf=1000000000000000001;
void solve(){
    int n;cin>>n;
    int mn=1000000001,mx=-1000000001;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        mn=min(mn,x);
        mx=max(mx,x);
    }
    cout<<mx-mn<<endl;
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

10 3
-5 -4 -3 -2 -1 0 1 2 3 4
1 0 4 1
1 5 9 1
2 0 9 3
**/