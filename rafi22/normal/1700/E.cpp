#include <bits/stdc++.h>

//#define int long long
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

int dx[5]={0,1,-1,0,0};
int dy[5]={0,0,0,1,-1};

vector<int>a[400007];
vector<int>is[400007];
vector<int>was[400007];
int n,m;

bool bad(int x,int y)
{
    if(x<=0||y<=0||x>n||y>m) return 0;
    if(a[x][y]==1) return 0;
    if(x>1&&a[x][y]>a[x-1][y]) return 0;
    if(x<n&&a[x][y]>a[x+1][y]) return 0;
    if(y>1&&a[x][y]>a[x][y-1]) return 0;
    if(y<m&&a[x][y]>a[x][y+1]) return 0;
    return 1;
}
int c=0;
void change(int x,int y)
{
    if(x<=0||y<=0||x>n||y>m) return ;
    c-=is[x][y];
    is[x][y]=bad(x,y);
    c+=is[x][y];
}

int check(int x1,int y1,int x2,int y2)
{
    if(x2<=0||y2<=0||x2>n||y2>m) return 0;
    swap(a[x1][y1],a[x2][y2]);
    for(int l=0;l<5;l++)
    {
        change(x1+dx[l],y1+dy[l]);
        change(x2+dx[l],y2+dy[l]);
    }
    bool ok=(c==0);
    swap(a[x1][y1],a[x2][y2]);
    for(int l=0;l<5;l++)
    {
        change(x1+dx[l],y1+dy[l]);
        change(x2+dx[l],y2+dy[l]);
    }
    return ok;
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
            a[i]=vector<int>(m+3,0);
            is[i]=vector<int>(m+3,0);
            was[i]=vector<int>(m+3,0);
            for(int j=1;j<=m;j++) cin>>a[i][j];
        }
        int px,py;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                change(i,j);
                if(is[i][j])
                {
                    px=i,py=j;
                }
            }
        }
        if(c==0)
        {
            cout<<0;
            return 0;
        }
        set<pair<pair<int,int>,pair<int,int>>>ans;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                for(int l=0;l<5;l++)
                {
                    if(check(i,j,px+dx[l],py+dy[l]))
                    {
                        if(make_pair(i,j)<make_pair(px+dx[l],py+dy[l])) ans.insert({{i,j},{px+dx[l],py+dy[l]}});
                        else ans.insert({{px+dx[l],py+dy[l]},{i,j}});
                    }
                }
            }
        }
        if(sz(ans)>0) cout<<1<<" "<<sz(ans)<<endl;
        else cout<<2<<endl;
    }

    return 0;
}