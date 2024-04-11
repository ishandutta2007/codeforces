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

const bool multi=1;

int d[507][507];
int D[507][507];
int R[507][507];

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
        int n,k;
        cin>>n>>k;
        memset(R,0,sizeof R);
        memset(D,0,sizeof D);
        for(int i=1;i<=n;i++)
        {
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            if(x1>x2) swap(x1,x2);
            if(y1>y2) swap(y1,y2);
            if(x1!=x2) R[x1][y1-1]++;
            else D[x1-1][y1]++;
            x1=k-x1+1;
            y1=k-y1+1;
            x2=k-x2+1;
            y2=k-y2+1;
            if(x1>x2) swap(x1,x2);
            if(y1>y2) swap(y1,y2);
            if(x1!=x2) R[x1][y1-1]++;
            else D[x1-1][y1]++;
        }
        for(int i=0;i<=k;i++) for(int j=0;j<=k;j++) d[i][j]=inf;
        priority_queue<pair<int,pair<int,int>>>Q;
        for(int i=0;i<=k;i++) Q.push({0,{0,i}});
        while(!Q.empty())
        {
            int x=Q.top().nd.st,y=Q.top().nd.nd,t=-Q.top().st;
            Q.pop();
            if(d[x][y]!=inf) continue;
            d[x][y]=t;
            if(x!=k) Q.push({-(t+D[x][y]),{x+1,y}});
            if(x!=0) Q.push({-(t+D[x-1][y]),{x-1,y}});
            if(y!=k) Q.push({-(t+R[x][y]),{x,y+1}});
            if(y!=0) Q.push({-(t+R[x][y-1]),{x,y-1}});
        }
        cout<<n-d[k/2][k/2]<<endl;
    }

    return 0;
}