#include <bits/stdc++.h>

#define int long long
#define double long double
//#define endl '\n'
#define st first
#define nd second
#define pb push_back
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;

bool odw[1007];
int pre[1007];
int post[1007];
int c=1;
vector <int> deph[1007];
vector <int> G[1007];

void clean()
{
    for(int i=0;i<=1000;i++)
    {
        odw[i]=0;
        pre[i]=0;
        post[i]=0;
        deph[i].clear();
        G[i].clear();
    }
}

void dfs(int v,int d)
{
    deph[d].pb(v);
    odw[v]=1;
    pre[v]=c++;
    for(auto u:G[v])
    {
        if(!odw[u])
        {
            dfs(u,d+1);
        }
    }
    post[v]=c++;
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
        clean();
        int n,a,b,p,d,p1,d1,x,y;
        cin>>n;
        for(int i=1;i<n;i++)
        {
            cin>>a>>b;
            G[a].pb(b);
            G[b].pb(a);
        }
        cout<<"? "<<n<<" ";
        for(int i=1;i<=n;i++) cout<<i<<" ";
        cout<<endl;
        cin>>p>>d;
        if(p==-1) return 0;
        dfs(p,0);
        int l=d/2+d%2,r=d,sr;
        while(l<=r)
        {
            sr=(l+r)/2;
            int ile=0;
            for(int i=sr;i<=r;i++) ile+=deph[i].size();
            if(ile==0)
            {
                r=sr-1;
                continue;
            }
            //cout<<l<<" "<<r<<endl;
            cout<<"? "<<ile<<" ";
            for(int i=sr;i<=r;i++)
            {
                for(int j=0;j<deph[i].size();j++) cout<<deph[i][j]<<" ";
            }
            cout<<endl;
            cin>>p1>>d1;
            if(p1==-1) return 0;
            if(d1==d)
            {
                l=sr+1;
                x=p1;
            }
            else
            {
                r=sr-1;
            }
        }

        int u=min(l,r);
        //cout<<l<<endl;
        if(d-u==0)
        {
            y=p;
        }
        else
        {
            int ile=deph[d-u].size()-((d-u)==u);
            for(int j=0; j<deph[d-u].size(); j++)
            {
                int o=deph[d-u][j];
                if((pre[o]<pre[x]&&post[o]>post[x])) ile--;
            }
            cout<<"? "<<ile<<" ";
            for(int j=0; j<deph[d-u].size(); j++)
            {
                int o=deph[d-u][j];
                if(o!=x&&!(pre[o]<pre[x]&&post[o]>post[x])) cout<<o<<" ";
            }
            cout<<endl;
            cin>>y>>d1;
            if(y==-1) return 0;
        }
        cout<<"! "<<x<<" "<<y<<endl;
        string str;
        cin>>str;
        if(str=="Incorrect") return 0;
    }

    return 0;
}