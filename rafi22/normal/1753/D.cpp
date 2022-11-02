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

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int n,m;

bool good(int x,int y)
{
    return x>0&&y>0&&x<=n&&y<=m;
}

signed main()
{
    mod=mod1;
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
        int p,q;
        cin>>p>>q;
        vector<vector<char>>a(n+3,vector<char>(m+3));
        vector<vector<int>>d(n+3,vector<int>(m+3,inf));
        vector<vector<int>>px(n+3,vector<int>(m+3,-1));
        vector<vector<int>>py(n+3,vector<int>(m+3,-1));
        priority_queue<pair<int,pair<int,int>>>Q;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
                if(a[i][j]=='.')
                {
                    d[i][j]=0;
                    Q.push({0,{i,j}});
                }
                if(a[i][j]=='L')
                {
                    px[i][j]=i;
                    py[i][j]=j+1;
                }
                if(a[i][j]=='R')
                {
                    px[i][j]=i;
                    py[i][j]=j-1;
                }
                if(a[i][j]=='D')
                {
                    px[i][j]=i-1;
                    py[i][j]=j;
                }
                if(a[i][j]=='U')
                {
                    px[i][j]=i+1;
                    py[i][j]=j;
                }
            }
        }
        int ans=inf;
        while(sz(Q)>0)
        {
            int x=Q.top().nd.st,y=Q.top().nd.nd;
            Q.pop();
          //  cout<<x<<" "<<y<<endl;
            for(int l=0;l<4;l++)
            {
                int nx=x+dx[l],ny=y+dy[l];
                if(!good(nx,ny)) continue;
                ans=min(ans,d[x][y]+d[nx][ny]);
            }
            for(int l=0;l<4;l++)
            {
                int nx=x+dx[l],ny=y+dy[l];
                if(!good(nx,ny)) continue;
                if(px[nx][ny]==-1) continue;
                int c;
                if(abs(px[nx][ny]-x)==2||abs(py[nx][ny]-y)==2) c=q;
                else c=p;
                if(d[px[nx][ny]][py[nx][ny]]>d[x][y]+c)
                {
                    d[px[nx][ny]][py[nx][ny]]=d[x][y]+c;
                    Q.push({-d[px[nx][ny]][py[nx][ny]],{px[nx][ny],py[nx][ny]}});
                }
            }
        }
        if(ans==inf) cout<<-1;
        else cout<<ans;
    }

    return 0;
}