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

const bool multi=0;

char tab[1007][1007];
bool odw[1007][1007];
int rowB[1007];
int rowBW[1007];
int colB[1007];
int colBW[1007];
bool r=1,c=1;
int n,m,res=0;

void dfs(int x,int y)
{
    odw[x][y]=1;
    if(x>n||x<1||y>m||y<1) return;
    if(!odw[x+1][y]) dfs(x+1,y);
    if(!odw[x-1][y]) dfs(x-1,y);
    if(!odw[x][y+1]) dfs(x,y+1);
    if(!odw[x][y-1]) dfs(x,y-1);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    if(multi)
        cin>>t;
    else t=1;
    while(t--)
    {

        cin>>n>>m;
        bool ok=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>tab[i][j];
                if(tab[i][j]=='.')
                {
                    if(rowB[i]) rowBW[i]=1;
                    if(colB[j]) colBW[j]=1;
                    odw[i][j]=1;
                }
                else
                {
                    if(rowBW[i]) ok=0;
                    if(colBW[j]) ok=0;
                    rowB[i]=1;
                    colB[j]=1;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(!rowB[i]) r=0;
        }
        for(int i=1;i<=m;i++)
        {
            if(!colB[i]) c=0;
        }
        for(int i=1;i<=n;i++)
        {
            bool x=1;
            for(int j=1;j<=m;j++)
            {
                if(tab[i][j]=='#') x=0;
            }
            if(x&&c) ok=0;
        }
        for(int j=1;j<=m;j++)
        {
            bool x=1;
            for(int i=1;i<=n;i++)
            {
                if(tab[i][j]=='#') x=0;
            }
            if(x&&r) ok=0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(!odw[i][j])
                {
                    res++;
                    dfs(i,j);
                }
            }
        }
        if(ok) cout<<res;
        else cout<<-1;
    }

    return 0;
}