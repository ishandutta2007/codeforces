#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,p;cin>>n>>p;
    for (int i=1;i<=12346;i++){
        int cur=n-p*i*1ll;
        if (cur>=i && __builtin_popcount(cur)<=i){
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}