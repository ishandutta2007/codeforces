//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=400004;
int suf[N];
int a[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    int res=0;
    for (int i=n;i>=1;i--){
        if (i+a[i]>n) suf[i]=a[i];
        else suf[i]=a[i]+suf[i+a[i]];
        res=max(res,suf[i]);
    }
    cout<<res<<endl;



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
/*

3 0
aa
bcd
*/