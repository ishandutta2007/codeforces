#include <bits/stdc++.h>

//#define int long long
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

int a[1007][1007];
int cnt[1000007];

deque<pair<int,int>>Q;
vector<pair<pair<int,int>,int>>ans;
int n,m;
int dx[4]={0,1,0,1};
int dy[4]={0,0,1,1};
int dx1[8]={1,-1,0,0,-1,1,-1,1};
int dy1[8]={0,0,1,-1,-1,1,1,-1};
void check(int i,int j)
{
    if(i<=0||j<=0||i>=n||j>=m) return ;
    int k=0;
    for(int l=0;l<4;l++)
    {
        int ni=i+dx[l],nj=j+dy[l];
        if(a[ni][nj]>0)
        {
            if(k>0&&k!=a[ni][nj]) return ;
            k=a[ni][nj];
        }
    }
    if(!k) return ;
    ans.pb({{i,j},k});
    Q.pb({i,j});
    for(int l=0;l<4;l++)
    {
        int ni=i+dx[l],nj=j+dy[l];
        a[ni][nj]=0;
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
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
        for(int i=1;i<n;i++) for(int j=1;j<m;j++) check(i,j);
        while(!Q.empty())
        {
            int i=Q[0].st,j=Q[0].nd;
            Q.pop_front();
            for(int l=0;l<8;l++)
            {
                int ni=i+dx1[l],nj=j+dy1[l];
                check(ni,nj);
            }
        }
        bool bad=0;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(a[i][j]>0) bad=1;
        if(bad) cout<<-1<<endl;
        else
        {
            reverse(all(ans));
            cout<<sz(ans)<<endl;
            for(auto x:ans) cout<<x.st.st<<" "<<x.st.nd<<" "<<x.nd<<endl;
        }
    }

    return 0;
}