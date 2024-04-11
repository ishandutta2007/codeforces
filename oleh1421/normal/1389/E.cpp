#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=100010;
int dp[N][6][2];
int a[N];
void solve(){
    int m,d,w;cin>>m>>d>>w;
    int cnt=0;
    m=min(m,d);
    w/=__gcd(w,d-1);
    ll dv=(m/w);
    ll res=w*(dv*(dv-1ll)/2ll);
//    cout<<res<<endl;;
//    m%=w;
    res+=(m%w)*dv;
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
1
12 30 7
*/