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
        int n;
        cin>>n;
        char tab[n+7][n+7];
        bool ok=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>tab[i][j];
            }
        }
        for(int i=0;i<=n;i++)
        {
            tab[n][i]='1';
            tab[i][n]='1';
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(tab[i][j]=='1')
                {
                    if(tab[i+1][j]=='0'&&tab[i][j+1]=='0') ok=0;
                }
            }
        }
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}