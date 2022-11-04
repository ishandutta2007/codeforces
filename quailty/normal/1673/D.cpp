#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod=1000000007;
ll solve()
{
    ll b,q,y,c,r,z;
    cin>>b>>q>>y>>c>>r>>z;
    if((c-b)%q!=0 || r%q!=0)return 0;
    ll st=(c-b)/q,ed=st+(r/q)*(z-1);
    if(st<0 || ed>=y)return 0;
    if(st<r/q || ed>=y-r/q)return -1;
    ll res=0;
    auto cal=[&](ll p)->ll
    {
        if(p/__gcd(p,q)*q!=r)return 0;
        return (r/p)*(r/p)%Mod;
    };
    for(ll i=1;i*i<=r;i++)
    {
        if(r%i!=0)continue;
        res=(res+cal(i))%Mod;
        if(i*i!=r)res=(res+cal(r/i))%Mod;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--)cout<<solve()<<endl;
    return 0;
}