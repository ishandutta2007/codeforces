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
    ll A=0ll,B=0ll;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        if (a[i]%2==0) A+=a[i];
        else B+=a[i];
    }
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    for (int i=1;i<=n;i++){
        if (i%2) A+=a[i];
        else B+=a[i];
    }
    if (A>B) cout<<"Alice\n";
    else if (A<B) cout<<"Bob\n";
    else cout<<"Tie\n";




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