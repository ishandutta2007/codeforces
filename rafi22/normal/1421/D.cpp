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
        int x,y,c1,c2,c3,c4,c5,c6,ans=0;
        cin>>x>>y>>c1>>c2>>c3>>c4>>c5>>c6;
        c1=min(c1,c6+c2);
        c2=min(c2,c1+c3);
        c3=min(c3,c2+c4);
        c4=min(c4,c3+c5);
        c5=min(c5,c4+c6);
        c6=min(c6,c5+c1);
        if(x>=0&&y>=0) cout<<min(x,y)*c1+(x-min(x,y))*c6+(y-min(x,y))*c2<<endl;
        else if(y>=0)
        {
            x=abs(x);
            cout<<c3*x+c2*y<<endl;
        }
        else if(x<=0&&y<=0)
        {
            x=abs(x);
            y=abs(y);
            cout<<min(x,y)*c4+(x-min(x,y))*c3+(y-min(x,y))*c5<<endl;
        }
        else if(x>=0)
        {
            y=abs(y);
            cout<<c6*x+c5*y<<endl;
        }
    }

    return 0;
}