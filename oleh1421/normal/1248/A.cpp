#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
//#define inf 1000000000000000001ll

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        ll n;cin>>n;
        ll cnt=0;
        for (int i=1;i<=n;i++){
            int x;cin>>x;
            cnt+=x%2;
        }
        ll m;cin>>m;
        ll cnt1=0;
        for (int i=1;i<=m;i++){
            int x;cin>>x;
            cnt1+=x%2;
        }
        cout<<cnt*cnt1*1ll+(n-cnt)*(m-cnt1)*1ll<<endl;
    }
    return 0;
}
/*

*/