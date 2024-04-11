#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
//#define endl '\n'
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

bool g[57][57][2];
bool DP[57][57][57][57][2];
bool was[57][57][57][57][2];

bool ask(int x1,int y1,int x2,int y2)
{
    cout<<"? "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
    bool b;
    cin>>b;
    return b;
}

bool policz(int x1,int y1,int x2,int y2,bool k)
{
    if((x1==x2&&y1==y2)||x2<x1||y2<y1) return 1;
    if(was[x1][y1][x2][y2][k]) return DP[x1][y1][x2][y2][k];
    was[x1][y1][x2][y2][k]=1;
    bool X;
    if(x1==x2) X=(g[x1][y1][k]==g[x2][y2][k])&(policz(x1,y1+1,x2,y2-1,k));
    else if(y1==y2) X=(g[x1][y1][k]==g[x2][y2][k])&(policz(x1+1,y1,x2-1,y2,k));
    else
    {
        X=0;
        if(x1+1<=x2-1) X|=policz(x1+1,y1,x2-1,y2,k);
        X|=policz(x1+1,y1,x2,y2-1,k);
        X|=policz(x1,y1+1,x2-1,y2,k);
        if(y1+1<=y2-1) X|=policz(x1,y1+1,x2,y2-1,k);
        X&=(g[x1][y1][k]==g[x2][y2][k]);
    }
    DP[x1][y1][x2][y2][k]=X;
    return X;
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
        int n;
        cin>>n;
        g[1][1][0]=1;
        g[2][2][0]=g[1][1][0]^(!ask(1,1,2,2));
        g[1][3][0]=g[1][1][0]^(!ask(1,1,1,3));
        g[2][3][0]=g[1][2][0]^(!ask(1,2,2,3));
        g[2][1][0]=g[2][3][0]^(!ask(2,1,2,3));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i<=2&&j<=3) continue;
                if(i==1) g[i][j][0]=g[i][j-2][0]^(!ask(i,j-2,i,j));
                else if(j==1) g[i][j][0]=g[i-2][j][0]^(!ask(i-2,j,i,j));
                else g[i][j][0]=g[i-1][j-1][0]^(!ask(i-1,j-1,i,j));
            }
        }
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) g[i][j][1]=g[i][j][0]^((i+j)%2);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                for(int x=i;x<=n;x++)
                {
                    for(int y=j;y<=n;y++)
                    {
                        policz(i,j,x,y,0);
                        policz(i,j,x,y,1);
                    }
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                for(int x=i;x<=n;x++)
                {
                    for(int y=j;y<=n;y++)
                    {
                        if(x-i+y-j<2) continue;
                        if(DP[i][j][x][y][0]!=DP[i][j][x][y][1])
                        {
                            bool good=ask(i,j,x,y);
                            bool b;
                            if(DP[i][j][x][y][0]==good) b=0;
                            else b=1;
                            cout<<"!"<<endl;
                            for(int i=1;i<=n;i++)
                            {
                                for(int j=1;j<=n;j++) cout<<g[i][j][b];
                                cout<<endl;
                            }
                            return 0;
                        }
                    }
                }
            }
        }
    }

    return 0;
}