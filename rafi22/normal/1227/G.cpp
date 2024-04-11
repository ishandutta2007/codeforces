#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

int a[1007];
int id[1007];
bool is[1007][1007];
bool xd[1007];

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
        int n,c;
        cin>>n;
        vector<pair<int,int>>V;
        for(int i=1;i<=n;i++)
        {
            cin>>c;
            V.pb({c,i});
        }
        sort(all(V),greater<pair<int,int>>());
        for(int i=0;i<sz(V);i++)
        {
            a[i+1]=V[i].st;
            id[i+1]=V[i].nd;
        }
        int x=0,y=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]!=a[i+1])
            {
                if(x+1==i)
                {
                    y++;
                    for(int j=y;j<=y+a[i]-1;j++) is[j][i]=1;
                }
                x=i;
            }
        }
        x=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]!=a[i+1])
            {
                if(x+1!=i)
                {
                    int d=max(0LL,(i-x-1)-a[i])+1;
                    int oy=y;
                    for(int j=x+1; j<=i; j++)
                    {
                        y++;
                        for(int l=x+1; l<=i; l++)
                        {
                            if(l>=j&&l<j+d) continue;
                            if(l<=j+d-1-(i-x)) continue;
                            is[y][l]=1;
                        }
                    }
                    int k=a[i]-(i-x)+1;
                  //  cout<<k<<endl;
                    for(int j=1; j<=oy&&k>0; j++)
                    {
                        for(int l=x+1; l<=i; l++) is[j][l]=1;
                        k--;
                    }
                    for(int j=y+1;j<=n+1&&k>0; j++)
                    {
                        for(int l=x+1; l<=i; l++) is[j][l]=1;
                        k--;
                    }
                }
                x=i;
            }
        }
        int ile=0;
        for(int j=1;j<=n+1;j++)
        {
            bool b=0;
            for(int l=1;l<=n;l++) b|=is[j][l];
          //  for(int l=1;l<=n;l++) cout<<is[j][l];
           // cout<<endl;
            ile+=b;
        }
        cout<<ile<<endl;
        for(int j=1;j<=n+1;j++)
        {
            bool b=0;
            for(int l=1;l<=n;l++) b|=is[j][l];
            if(!b) continue;
            memset(xd,0,sizeof xd);
            for(int l=1;l<=n;l++) xd[id[l]]=is[j][l];
            for(int l=1;l<=n;l++) cout<<xd[l];
            cout<<endl;
        }
    }

    return 0;
}