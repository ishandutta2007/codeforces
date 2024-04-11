#include <iostream>
using namespace std;
typedef long long ll;

inline ll max(ll a,ll b){ return a>b?a:b; }
inline ll min(ll a,ll b){ return a>b?b:a; }

int main()
{
    ll n,a,b,c;
    cin>>n>>a>>b>>c;
    ll tmp = max(0,n-b)/min(a,b-c);
    ll ans = tmp;
    n-=tmp*min(a,b-c);
    if(a>b-c)
    while(n>=b){
        n-=(b-c);
        ++ans;
    }
    cout<<ans+n/a;
    return 0;
}