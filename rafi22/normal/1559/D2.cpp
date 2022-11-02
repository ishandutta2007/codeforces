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

int o[100007][2];
int s[100007][2];

int Find(int v,bool b)
{
    if(o[v][b]==v) return v;
    return Find(o[v][b],b);
}
void Union(int u,int v,bool b)
{
    if(s[u][b]<s[v][b])
    {
        o[u][b]=v;
        s[v][b]+=s[u][b];
    }
    else
    {
        o[v][b]=u;
        s[u][b]+=s[v][b];
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
        int n,m1,m2;
        cin>>n>>m1>>m2;
        for(int i=1;i<=n;i++)
        {
            o[i][0]=i;
            o[i][1]=i;
            s[i][0]=1;
            s[i][1]=1;
        }
        while(m1--)
        {
            int u,v;
            cin>>u>>v;
            u=Find(u,0),v=Find(v,0);
            Union(u,v,0);
        }
        while(m2--)
        {
            int u,v;
            cin>>u>>v;
            u=Find(u,1),v=Find(v,1);
            Union(u,v,1);
        }
        vector<pair<int,int>>ans;
        for(int i=1;i<=n;i++)
        {
            int u=Find(i,0),v=Find(1,0),u1=Find(i,1),v1=Find(1,1);
            if(u!=v&&u1!=v1)
            {
                Union(u,v,0);
                Union(u1,v1,1);
                ans.pb({i,1});
            }
        }
        for(int i=1;i<=n;i++)
        {
            int u=Find(i,0),v=Find(1,0),u1=Find(i,1),v1=Find(1,1);
            if(u!=v&&u1!=v1)
            {
                Union(u,v,0);
                Union(u1,v1,1);
                ans.pb({i,1});
            }
        }
        vector<int>X,Y;
        for(int i=2;i<=n;i++)
        {
            if(Find(i,0)!=Find(1,0)) X.pb(i);
            else if(Find(i,1)!=Find(1,1)) Y.pb(i);
        }
        while(sz(X)>0&&sz(Y)>0)
        {
            if(Find(X.back(),0)==Find(1,0)) X.pop_back();
            else if(Find(Y.back(),1)==Find(1,1)) Y.pop_back();
            else
            {
                ans.pb({X.back(),Y.back()});
                Union(Find(X.back(),0),Find(Y.back(),0),0);
                Union(Find(X.back(),1),Find(Y.back(),1),1);
                X.pop_back();
                Y.pop_back();
            }
        }
        cout<<sz(ans)<<endl;
        for(auto x:ans) cout<<x.st<<" "<<x.nd<<endl;
    }

    return 0;
}