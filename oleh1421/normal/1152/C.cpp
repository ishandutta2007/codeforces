#include <iostream>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;
ll nsk(ll a,ll b){
   return (a/__gcd(a,b))*b*1ll;
}
int main()
{
    ll a,b;cin>>a>>b;
    if (a==b){
        cout<<0;
        return 0;
    }
    if (a>b) swap(a,b);
    vector<ll>d;
    for (ll i=1;i*i<=b-a;i++){
            if ((b-a)%i) continue;
            d.push_back(i*1ll);
            d.push_back((b-a)/i*1ll);
    }
    sort(d.begin(),d.end());
    ll k=0;
    for (auto i:d){
        if (i>=a){
            cout<<i-a;
            return 0;
        }
    }
    ll minx=(a*1ll/__gcd(a*1ll,b*1ll))*b*1ll;
    ll mink=0;
    for (auto i:d){
        ll k=(i-a%i)%i;
        ll cur=nsk(a+k,b+k);
        if (cur<minx){
            minx=cur;
            mink=k;
        }

    }
    cout<<mink;
    return 0;
}