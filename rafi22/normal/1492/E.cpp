#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

vector<int>a[250007];
void gg()
{
    cout<<"No";
    exit(0);
}
int n,m;

void check(vector<int>v,int w)
{
    bool ok=1;
    for(int i=1;i<=n;i++)
    {
        int cnt=0;
        bool iw=0;
        for(int j=0;j<m;j++)
        {
            if(v[j]!=a[i][j])
            {
                if(j==w) iw=1;
                else cnt++;
            }
        }
        if(cnt>2) ok=0;
        if(cnt==2&&iw)
        {
            v[w]=a[i][w];
            w=inf;
        }
    }

    if(ok)
    {
        cout<<"Yes"<<endl;
        for(auto x:v)
        {
            if(x==inf) cout<<1<<" ";
            else cout<<x<<" ";
        }
        exit(0);
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

        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int x;
                cin>>x;
                a[i].pb(x);
            }
        }
        for(int i=2;i<=n;i++)
        {
            vector<int>d;
            for(int j=0;j<m;j++) if(a[1][j]!=a[i][j]) d.pb(j);
            if(sz(d)>4) gg();
            else if(sz(d)==4)
            {
                for(int j=0;j<4;j++)
                {
                    for(int l=j+1;l<4;l++)
                    {
                        vector<int>xd=a[1];
                        xd[d[j]]=a[i][d[j]];
                        xd[d[l]]=a[i][d[l]];
                        check(xd,inf);
                    }
                }
                gg();
            }
            else if(sz(d)==3)
            {
                for(int j=0;j<3;j++)
                {
                    for(int l=0;l<3;l++)
                    {
                        if(j==l) continue;
                        vector<int>xd=a[1];
                        xd[d[j]]=a[i][d[j]];
                        xd[d[l]]=inf;
                        check(xd,d[l]);
                    }
                }
                gg();
            }
        }
        cout<<"Yes"<<endl;
        for(auto x:a[1]) cout<<x<<" ";
    }

    return 0;
}