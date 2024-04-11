#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=300020;
int a[N];
bool same(int x,int y){
    if (x<0 && y<0) return true;
    if (x>0 && y>0) return true;
    return false;
}
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int mx=a[1];
    ll sum=0ll;
    for (int i=2;i<=n;i++){
        if (same(a[i],a[i-1])) mx=max(mx,a[i]);
        else {
            sum+=mx;
            mx=a[i];
        }
    }
    sum+=mx;
    cout<<sum<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}