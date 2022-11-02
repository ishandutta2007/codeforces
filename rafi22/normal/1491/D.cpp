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

vector<int>G[10007];
bool odw[1007][1007];

void dfs(int v,int r)
{
    odw[r][v]=1;
    for(auto u:G[v])
    {
        if(!odw[r][u]) dfs(u,r);
    }
}

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
        int q;
        cin>>q;
        while(q--)
        {
            int u,v;
            cin>>u>>v;
            if(v<u) cout<<"NO"<<endl;
            else
            {
                bool b=1;
                int balance=0;
                for(int k=0;k<30;k++)
                {
                    if(u%2) balance++;
                    if(v%2) balance--;
                    if(balance<0) b=0;
                    u/=2;
                    v/=2;
                }
                if(b) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
        }
    }

    return 0;
}