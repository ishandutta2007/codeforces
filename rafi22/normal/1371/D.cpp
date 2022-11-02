#include <bits/stdc++.h>

#define int long long
#define endl '\n'
using namespace std;

char tab[307][307];
int ile[307];
int ile1[307];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,mini1=1000000007,maxi1=0,mini2=1000000007,maxi2=0;
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            ile[i]=0;
            ile1[i]=0;
            for(int j=1;j<=n;j++)
            {
                 tab[i][j]='0';
            }
        }
        for(int i=1;i<=min(n,k);i++)
        {
            tab[i][i]='1';
            ile[i]++;
            ile1[i]++;
        }
        k-=min(n,k);
        int it1=2,it2=n;
        int x1=1,x2=n,y1=2,y2=1;
        bool kolej=1;
        for(int i=0;i<k;i++)
        {
            if(kolej)
            {
                tab[x1][y1]='1';
                ile[x1]++;
                ile1[y1]++;
                x1++;
                y1++;
                if(x1>n||y1>n)
                {
                    x1=1;
                    y1=++it1;
                    kolej=0;
                }
            }
            else
            {
                tab[x2][y2]='1';
                ile[x2]++;
                ile1[y2]++;
                x2++;
                y2++;
                if(x2>n||y2>n)
                {
                    y2=1;
                    x2=--it2;
                    kolej=1;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            mini1=min(ile[i],mini1);
            maxi1=max(ile[i],maxi1);
        }
        for(int i=1;i<=n;i++)
        {
            mini2=min(ile1[i],mini2);
            maxi2=max(ile1[i],maxi2);
        }
        cout<<(maxi1-mini1)*(maxi1-mini1)+(maxi2-mini2)*(maxi2-mini2)<<endl;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                 cout<<tab[i][j];
            }
            cout<<endl;
        }



    }
    return 0;
}