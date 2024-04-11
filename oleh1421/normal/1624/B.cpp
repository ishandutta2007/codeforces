#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200100;
const ll inf=1000000000000000001;
ll a[3];
void solve(){
    cin>>a[0]>>a[1]>>a[2];
    if (a[1]*2-a[0]>0 && ((a[1]*2-a[0])%a[2]==0)){
        cout<<"YES\n";
        return;
    }
    reverse(a,a+3);
    if (a[1]*2-a[0]>0 && ((a[1]*2-a[0])%a[2]==0)){
        cout<<"YES\n";
        return;
    }
    if ((a[0]+a[2])%2==0 && ((a[0]+a[2])/2)%a[1]==0){
        cout<<"YES\n";
        return;
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

10 3
-5 -4 -3 -2 -1 0 1 2 3 4
1 0 4 1
1 5 9 1
2 0 9 3
**/