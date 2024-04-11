#include <bits/stdc++.h>

//#define int long long
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

int a[1007][1007];
int px[1007][1007];
int py[1007][1007];
int dx[1007];
int dy[1007];

unordered_map<int,int>pos;

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
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        for(int i=1;i<=n;i++)
        {
            set<int>S;
            for(int j=1;j<=m;j++) S.insert(a[i][j]);
            int it=0;
            dx[i]=sz(S);
            for(auto x:S) pos[x]=++it;
            for(int j=1;j<=m;j++) px[i][j]=pos[a[i][j]];
        }
        for(int j=1;j<=m;j++)
        {
            set<int>S;
            for(int i=1;i<=n;i++) S.insert(a[i][j]);
            int it=0;
            dy[j]=sz(S);
            for(auto x:S) pos[x]=++it;
            for(int i=1;i<=n;i++) py[i][j]=pos[a[i][j]];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cout<<max(px[i][j],py[i][j])+max(dx[i]-px[i][j],dy[j]-py[i][j])<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}