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
        int n,ans=0;
        int ile[25][25];
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                ile[i][j]=0;
            }
        }
        cin>>n;
        string a,b;
        cin>>a>>b;
        bool ok=1;
        for(int i=0;i<n;i++)
        {
            if(a[i]>b[i]) ok=0;
            else if(a[i]!=b[i])
            {
                ile[a[i]-97][b[i]-97]++;
            }
        }
        if(ok==0) cout<<-1<<endl;
        else
        {
            for(int i=0;i<=19;i++)
            {
                int mn=inf;
                for(int j=0;j<=19;j++)
                {
                    if(ile[i][j]!=0)
                    {
                        mn=j;
                        break;
                    }
                }
                if(mn!=inf)
                {
                    ile[i][mn]=0;
                    ans++;
                    for(int j=0;j<=19;j++) ile[mn][j]+=ile[i][j];

                }
            }
            cout<<ans<<endl;
        }
    }


    return 0;
}