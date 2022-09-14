#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define int ll
#define endl '\n'
const int N=100100;
const ll mod=998244353;
int a[N];
void solve(){
    int n;cin>>n;
    int sum=0;
    int mx=0;
    for (int i=1;i<=n;i++) cin>>a[i],sum+=a[i],mx=max(mx,a[i]);
    if (mx>sum-mx){
        cout<<"T\n";
        return;
    }
    if (sum%2){
        cout<<"T\n";
        return;
    }
    cout<<"HL\n";

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
//1 3 3 4
//0 1 2 3