#include <bits/stdc++.h>

//#define int long long
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

int a[100007];
int b[100007];
int r1[100007];
int r2[100007];
void cnt(int j,int n)
{
    if(j<=n&&b[j+a[j]]==b[j])
    {
        r1[j]=r1[j+a[j]];
        r2[j]=r2[j+a[j]]+1;
    }
    else
    {
        r1[j]=j;
        r2[j]=1;
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
        int n,m,s,c=1,u,v;
        cin>>n>>m;
        s=sqrt(n)+sqrt(n)/2;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++)
        {
            b[i]=c;
            if(i%s==0) c++;
        }
        for(int j=n;j>0;j--)
        {
            if(j+a[j]<=n&&b[j+a[j]]==b[j])
            {
                r1[j]=r1[j+a[j]];
                r2[j]=r2[j+a[j]]+1;
            }
            else
            {
                r1[j]=j;
                r2[j]=1;
            }
        }
        bool t;
        for(int l=2;l<=m+1;l++)
        {
            cin>>t;
            if(t)
            {
                cin>>u;
                int a1=0,a2=0,act=u;
                while(true)
                {
                    a2+=r2[act];
                    if(r1[act]+a[r1[act]]<=n) act=r1[act]+a[r1[act]];
                    else
                    {
                        a1=r1[act];
                        break;
                    }
                }
                cout<<a1<<" "<<a2<<endl;
            }
            else
            {
                cin>>u>>v;
                a[u]=v;
                for(int j=u; b[j]==b[u]; j--)
                {
                    if(j+a[j]<=n&&b[j+a[j]]==b[j])
                    {
                        r1[j]=r1[j+a[j]];
                        r2[j]=r2[j+a[j]]+1;
                    }
                    else
                    {
                        r1[j]=j;
                        r2[j]=1;
                    }
                }
            }

        }
    }

    return 0;
}