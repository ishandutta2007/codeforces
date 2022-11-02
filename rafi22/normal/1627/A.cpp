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
        int n,m,r,c;
        cin>>n>>m>>r>>c;
        bool b=0,R=0,C=0,ok=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                char x;
                cin>>x;
                if(x=='B')
                {
                    b=1;
                    if(i==r) R=1;
                    if(j==c) C=1;
                    if(i==r&&j==c) ok=1;
                }
            }
        }
        if(!b) cout<<-1;
        else if(ok) cout<<0;
        else if(R||C) cout<<1;
        else cout<<2;
        cout<<endl;
    }

    return 0;
}