#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200100;
const ll mod=998244353;
int a[N];
int b[N];
void solve(){
    int n;cin>>n;
    int mx=0;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        mx=max(mx,a[i]);
        b[i]=mx-a[i];
    }
    ll res=0;
    for (int i=2;i<=n;i++){
        res+=max(0,b[i]-b[i-1]);
    }
    cout<<res<<endl;
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