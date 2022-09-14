//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long ll;
typedef long double ld;
///#define int ll
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
const int N=1000010;
int a[N];
void solve(){
    int n;cin>>n;
    int k;cin>>k;
    if (n==4 && k==3){
        cout<<-1<<endl;
        return;
    }
    if (k==n-1){
        int bt=0;
        for (int i=0;i<20;i++){
            if (k&(1<<i)){
                bt=i;
                break;
            }
        }
        cout<<n-2<<" "<<n-1<<endl;
        cout<<1<<" "<<n-3<<endl;
        cout<<0<<" "<<2<<endl;
        for (int i=3;i<n/2;i++){
            cout<<i<<" "<<n-i-1<<endl;
        }
        return;
    }
    if (k==0){
        for (int i=0;i<n/2;i++) cout<<i<<" "<<n-i-1<<endl;
        return;
    }

    cout<<0<<" "<<n-1-k<<endl;
    cout<<k<<" "<<n-1<<endl;
    for (int i=1;i<n/2;i++){
        if (i!=k && i!=n-1-k) cout<<i<<" "<<n-i-1<<endl;
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