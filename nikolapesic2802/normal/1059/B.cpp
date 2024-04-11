#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

int main()
{
    int n,m;
    scanf("%i %i",&n,&m);
    vector<string> oblik(n);
    char s[m+1];
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        oblik[i]=s;
    }
    vector<vector<int> > odstampan(n,vector<int>(m));
    vector<pair<int,int> > tacke={{0,0},{1,0},{2,0},{0,1},{0,2},{2,2},{1,2},{2,1}};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(oblik[i][j]=='#')
            {
                if(j<m-2&&i<n-2)
                {
                    //printf("Usao za %i %i\n",i,j);
                    int test=1;
                    for(auto p:tacke)
                    {
                        int x=i+p.first;
                        int y=j+p.second;
                        if(oblik[x][y]!='#')
                        {
                            test=0;
                        }
                    }
                    if(test)
                    {
                        for(auto p:tacke)
                        {
                            int x=i+p.first;
                            int y=j+p.second;
                            odstampan[x][y]=1;
                        }
                    }
                }
            }
        }
    }
    bool test=true;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(oblik[i][j]=='#'&&odstampan[i][j]==0)
            {
                test=false;
            }
        }
    }
    if(test)
        printf("YES\n");
        else
            printf("NO\n");
    return 0;
}