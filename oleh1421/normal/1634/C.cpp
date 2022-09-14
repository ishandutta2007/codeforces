#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
#define endl '\n'
using namespace std;
const int N=5000010;
const ll mod=998244353;

void solve(){
    int n,m;cin>>n>>m;
    if (m==1){
        cout<<"YES\n";
        for (int i=1;i<=n;i++) cout<<i<<endl;
        return;
    }
    if (n%2){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    int cur=1;
    for (int i=1;i<=n/2;i++){
        for (int j=1;j<=m;j++){
            cout<<cur<<" ";
            cur+=2;
        }
        cout<<endl;
    }
    cur=2;
    for (int i=1;i<=n/2;i++){
        for (int j=1;j<=m;j++){
            cout<<cur<<" ";
            cur+=2;
        }
        cout<<endl;
    }

}
int32_t  main()
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