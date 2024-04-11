//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=300010;
mt19937 rnd(time(nullptr));
int val[N];
void solve(){
    int n;cin>>n;
    ll res=0ll;
    for (ll i=1;i<n;i++){
        res+=max(i,n-i-1ll)*max(i,n-i-1ll);
    }
    cout<<res<<endl;
    int k=n/2;
    cout<<k+1<<" ";
    for (int i=1;i<k;i++) cout<<i<<" ";
    for (int i=k+2;i<=n;i++) cout<<i<<" ";
    cout<<k<<endl;
    cout<<n-1<<endl;
    for (int i=k;i>=2;i--){
        cout<<i<<" "<<n<<endl;
    }
    for (int i=k+1;i<n;i++){
        cout<<i<<" "<<1<<endl;
    }
    cout<<1<<" "<<n<<endl;

}
int32_t main()
{
//
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}

//4 1 2 3
//3 1 2 4
//2 1 3 4
//1 2 3 4
//2 3 1
//a[i]-a[i-1]+a[i-2]-a[i-3]+...