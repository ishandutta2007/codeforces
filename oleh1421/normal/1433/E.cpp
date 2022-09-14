#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=5010;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;cin>>n;
    ll res=1ll;
    for (ll i=1;i<=n;i++){
        res*=i;
    }
    res/=2ll;
    res/=(n/2ll);
    res/=(n/2ll);
    cout<<res<<endl;
    return 0;
}