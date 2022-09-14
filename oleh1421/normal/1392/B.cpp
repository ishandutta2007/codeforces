#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200100;
const ll mod=998244353;
int a[N];
void solve(){
    int n;cin>>n;
    ll k;cin>>k;
    if (k>=2){
        k=2+k%2;
    }
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int it=1;it<=k;it++){
        int mx=-1000000001;
        for (int i=1;i<=n;i++) mx=max(mx,a[i]);
        for (int i=1;i<=n;i++) a[i]=mx-a[i];
    }
    for (int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}