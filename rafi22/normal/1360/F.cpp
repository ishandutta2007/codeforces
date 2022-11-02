#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        bool take=0;
        cin>>n>>m;
        string str[n],act;
        for(int i=0;i<n;i++) cin>>str[i];
        for(int i=0;i<m;i++)
        {
            for(int j=97;j<123;j++)
            {
                bool ok=1;
                act=str[0];
                act[i]=(char)j;
                for(int k=1;k<n;k++)
                {
                    int ile=0;
                    for(int l=0;l<m;l++)
                    {
                        if(act[l]!=str[k][l]) ile++;
                    }
                    if(ile>1) ok=0;
                }
                if(ok)
                {
                    cout<<act<<endl;
                    take=1;
                }
                if(take) break;
            }
            if(take) break;
        }
        if(!take) cout<<-1<<endl;
    }
    return 0;
}