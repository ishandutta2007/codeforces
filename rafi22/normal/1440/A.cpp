#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;

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
        int n,c0,c1,h,z=0,o=0;
        cin>>n>>c0>>c1>>h;
        string str;
        cin>>str;
        for(auto ch:str)
        {
            if(ch=='0') z++;
            else o++;
        }
        if(c1>c0)
        {
            if(c1-c0>h) cout<<n*c0+h*o<<endl;
            else cout<<c0*z+c1*o<<endl;
        }
        else if(c0>c1)
        {
            if(c0-c1>h) cout<<n*c1+h*z<<endl;
            else cout<<c0*z+c1*o<<endl;
        }
        else cout<<c0*z+c1*o<<endl;
    }

    return 0;
}