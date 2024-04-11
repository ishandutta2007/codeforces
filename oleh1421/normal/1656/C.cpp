#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
const int N=2000010;
const ll mod=1000000007;
const int L=20;
const ll inv2=(mod+1)/2;
ll a[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    if (a[1]==a[n]){
        cout<<"YES\n";
        return;
    }
    bool ok=true;
    for (int i=1;i<=n;i++){
        if (a[i]==1){
            ok=false;
        }
    }
    if (ok){
        cout<<"YES\n";
        return;
    }
    for (int i=1;i<=n;i++){
        if (a[i]==0){
            cout<<"NO\n";
            return;
        }
    }
    for (int i=2;i<=n;i++){
        if (a[i]==a[i-1]+1){
            cout<<"NO\n";
            return;
        }
    }


    cout<<"YES\n";
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

//2
//
//1 2

/**



**/