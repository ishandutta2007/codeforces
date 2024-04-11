//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
typedef long double ld;
//#define double ld
using namespace std;
const int N=100025;
void solve(){
    int n,x;cin>>n>>x;
    int cnt0=0,cnt1=0;
    for (int i=1;i<=n;i++){
        int a;cin>>a;
        if (a%2) cnt1++;
        else cnt0++;
    }
    if (cnt1==0){
        cout<<"No\n";
    } else if (cnt0==0){
        if (x%2) cout<<"Yes\n";
        else cout<<"No\n ";
    } else {
        if (cnt1%2==0) cnt1--;
        if (cnt1+cnt0>=x) cout<<"Yes\n";
        else cout<<"No\n";
    }
}
int main()
{
//    freopen("fuel.in","r",stdin);
//    freopen("fuel.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}