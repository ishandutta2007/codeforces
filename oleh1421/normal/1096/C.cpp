#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll nsk(ll a,ll b){
   return (a/__gcd(a,b))*b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while (t--){
        ll a;cin>>a;
       // cout<<nsk(180ll,a)<<" ";
        ll n=nsk(180ll,a)/a;
        while ((n*a)/180ll>n-2ll) n*=2;
        cout<<n<<'\n';
    }
    return 0;
}