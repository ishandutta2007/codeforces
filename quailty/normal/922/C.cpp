#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,k;
    scanf("%lld%lld",&n,&k);
    set<ll> st;
    for(ll i=1;i<=k;i++)
    {
        ll r=n%i;
        if(st.find(r)!=st.end())
            return 0*printf("No\n");
        st.insert(r);
    }
    return 0*printf("Yes\n");
}