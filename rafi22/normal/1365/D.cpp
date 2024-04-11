#include <bits/stdc++.h>

using namespace std;

char tab[67][67];
bool odw[67][67];
bool good[67][67];
vector <pair<int,int>> v;
int n,m;

bool b;

void dfs(int i,int j)
{
    if(i<n&&tab[i+1][j]=='B') return;
    if(i>1&&tab[i-1][j]=='B') return;
    if(j<m&&tab[i][j+1]=='B') return;
    if(j>1&&tab[i][j-1]=='B') return;
    if(i==n&&j==m) b=1;
    if(tab[i][j]=='G') v.push_back(make_pair(i,j));
    odw[i][j]=1;
    if(tab[i+1][j]!='#'&&odw[i+1][j]!=1&&tab[i+1][j]!='B'&&i<n) dfs(i+1,j);
    if(tab[i-1][j]!='#'&&odw[i-1][j]!=1&&tab[i-1][j]!='B'&&i>1) dfs(i-1,j);
    if(tab[i][j+1]!='#'&&odw[i][j+1]!=1&&tab[i][j+1]!='B'&&j<m) dfs(i,j+1);
    if(tab[i][j-1]!='#'&&odw[i][j-1]!=1&&tab[i][j-1]!='B'&&j>1) dfs(i,j-1);
}

void fil()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(odw[i][j]) good[i][j]=1;
        }
    }
}

void clean()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            odw[i][j]=0;
        }
    }
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>tab[i][j];
                odw[i][j]=0;
            }
        }
        bool is=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(tab[i][j]=='G'&&is)
                {
                    v.clear();
                    b=0;
                    clean();
                    dfs(i,j);
                    if(b)
                    {
                        for(int k=0;k<v.size();k++)
                        {
                            tab[v[k].first][v[k].second]='.';
                        }
                    }
                    if(!b) is=0;
                }
            }
        }
        if(tab[n][m]=='B') is=0;
        if(is) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}