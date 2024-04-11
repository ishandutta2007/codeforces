#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int l=0;l<t;l++)
    {
        int n,m,x,y;
        cin>>n>>m>>x>>y;
        char tab[n+7][m+7];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>tab[i][j];
            }
        }
        for(int i=1;i<=n;i++) tab[i][m+1]='*';
        int res=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(tab[i][j]=='.'&&tab[i][j+1]=='.')
                {
                    tab[i][j]='*';
                    tab[i][j+1]='*';
                    res+=min(2*x,y);
                }
                else if(tab[i][j]=='.')
                {
                    tab[i][j]='*';
                    res+=x;
                }
            }
        }
        cout<<res<<endl;
    }



    return 0;
}