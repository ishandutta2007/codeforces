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

const bool multi=0;

map<int,char>G[200007];

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
        int n,q,cnt=0,cnt1=0;
        cin>>n>>q;
        while(q--)
        {
            char z,c;
            int a, b;
            cin>>z;
            if(z=='+')
            {
                cin>>a>>b>>c;
                G[a][b]=c;
                if(G[b][a]>0) cnt++;
                if(G[b][a]==c) cnt1++;
            }
            else if(z=='-')
            {
                cin>>a>>b;
                if(G[b][a]>0) cnt--;
                if(G[b][a]==G[a][b]) cnt1--;
                G[a][b]=0;
            }
            else
            {
                cin>>a;
                if(a%2)
                {
                    if(cnt) cout<<"YES"<<endl;
                    else cout<<"NO"<<endl;
                }
                else
                {
                    if(cnt1) cout<<"YES"<<endl;
                    else cout<<"NO"<<endl;
                }
            }
        }
    }

    return 0;
}