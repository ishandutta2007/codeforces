#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
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
        int x,y,c1=0,c2=0,d1=0,d2=0;
        cin>>x>>y;
        string s;
        cin>>s;
        for(auto i:s)
        {
            if(i=='U') c1++;
            if(i=='D') c2++;
            if(i=='R') d1++;
            if(i=='L') d2++;
        }
        bool ans=1;
        if(x>=0&&x>d1) ans=0;
        if(x<0&&-x>d2) ans=0;
        if(y>=0&&y>c1) ans=0;
        if(y<0&&-y>c2) ans=0;
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}