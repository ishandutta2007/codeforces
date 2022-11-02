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
        int n,m;
        cin>>n>>m;
        bool eR=0,eW=0,oR=0,oW=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                char c;
                cin>>c;
                if(c=='W')
                {
                    if((i+j)%2) oW=1;
                    else eW=1;
                }
                else if(c=='R')
                {
                    if((i+j)%2) oR=1;
                    else eR=1;
                }
            }
        }
        if((oR&&oW)||(eR&&eW)||(oR&&eR)||(oW&&eW)) cout<<"No"<<endl;
        else
        {
            cout<<"Yes"<<endl;
            if(eR+eW+oR+oW==0)
            {
                eR=1;
                oW=1;
            }
            if(eR) oW=1;
            if(eW) oR=1;
            if(oW) eR=1;
            if(oR) eW=1;
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    if((i+j)%2)
                    {
                        if(oR) cout<<'R';
                        else cout<<'W';
                    }
                    else
                    {
                        if(eR) cout<<'R';
                        else cout<<'W';
                    }
                }
                cout<<endl;
            }
        }
    }

    return 0;
}