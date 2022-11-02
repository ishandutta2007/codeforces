#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int r;
        cin>>r;
        if(r<1200) cout<<1200;
        else if(r<1400) cout<<1400;
        else if(r<1600) cout<<1600;
        else if(r<1900) cout<<1900;
        else if(r<2100) cout<<2100;
        else if(r<2300) cout<<2300;
        else if(r<2400) cout<<2400;
        else if(r<2600) cout<<2600;
        else if(r<3000) cout<<3000;
    }

    return 0;
}