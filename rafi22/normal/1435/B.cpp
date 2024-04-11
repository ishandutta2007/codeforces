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

int pos[300007];
int tab[1007][1007];

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
        int n,m,a;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a;
                pos[a]=j;
            }
        }
        vector <pair<int,int>>vec;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>tab[i][j];
            }
            vec.pb({pos[tab[i][1]],i});
        }
        sort(vec.begin(),vec.end());
        for(int i=1;i<=n;i++)
        {
            for(auto p:vec)
            {
                cout<<tab[p.nd][i]<<" ";
            }
            cout<<endl;
        }




    }

    return 0;
}