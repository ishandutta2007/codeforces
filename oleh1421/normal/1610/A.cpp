//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
#define endl '\n'
using namespace std;
const int N=2000010;
const ll mod=1000000007ll;
void solve(){
    int n,m;cin>>n>>m;
    if (n==1 && m==1){
        cout<<0<<endl;
        return;
    }
    if (n==1 || m==1){
        cout<<1<<endl;
        return;
    }
    cout<<2<<endl;
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