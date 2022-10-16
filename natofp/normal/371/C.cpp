#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a,b,c;
ll koszta,kosztb,kosztc;
ll r;
long long int ilea,ileb,ilec;

bool czy(ll x)
{
    ll wyn=0;
    wyn+=max(0LL,(ilea*x-a)*koszta);
    wyn+=max(0LL,(ileb*x-b)*kosztb);
    wyn+=max(0LL,(ilec*x-c)*kosztc);
    if(wyn<=r) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='B') ilea++;
        else if(s[i]=='S') ileb++;
        else ilec++;
    }
    cin>>a>>b>>c;
    cin>>koszta>>kosztb>>kosztc;
    cin>>r;
    ll lo,hi;
    lo=0;
    hi=1e12;
    while(lo+1<hi)
    {
        ll mid=(lo+hi)/2;
        bool ok=czy(mid);
        if(ok==true)
        {
            lo=mid;
        }
        else hi=mid;
    }
    while(czy(lo)==true) lo++;
    lo--;
    cout<<lo<<endl;
    return 0;
}