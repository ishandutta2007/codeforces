//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=44;

void solve(){
    int cnt1=0,cnt2=0;
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        if (x==1) cnt1++;
        else cnt2++;
    }
    if (cnt1%2 || (cnt1==0 && cnt2%2)){
        cout<<"NO\n";
    } else cout<<"YES\n";

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