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

const bool multi=1;
int cnt[200007];
vector<int>v[200007];
vector<int>v1[200007];
int ans[200007];
bool odw[200007];
int xd[200007];

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
        for(int i=1;i<=m;i++)
        {
            int k;
            cin>>k;
            for(int j=0;j<k;j++)
            {
                int a;
                cin>>a;
                v[i].pb(a);
                v1[a].pb(i);
                cnt[a]++;
            }
        }
        set<pair<int,int>>Q;
        for(int i=1;i<=n;i++) Q.insert({cnt[i],i});
        int emp=m;
        while(sz(Q)>0)
        {
            pair<int,int>p=*Q.begin();
            Q.erase(Q.begin());
            if(cnt[p.nd]>m/2+m%2) break;
            odw[p.nd]=1;
            for(auto x:v1[p.nd])
            {
                if(!ans[x])
                {
                    ans[x]=p.nd;
                    emp--;
                    for(auto y:v[x])
                    {
                        if(!odw[y])
                        {
                            Q.erase({cnt[y],y});
                            cnt[y]--;
                            Q.insert({cnt[y],y});
                        }
                    }
                }
            }
            if(emp==0) break;
        }
        for(int i=1;i<=m;i++)
        {
            if(!ans[i])
            {
                int ile=0;
                for(auto x:v[i]) if(!odw[x]&&xd[x]<m/2+m%2) ile++;
                if(ile==1)
                {
                    for(auto x:v[i])
                    {
                        if(!odw[x])
                        {
                            xd[x]++;
                            ans[i]=x;
                            emp--;
                            break;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=m;i++)
        {
            if(!ans[i])
            {
                for(auto x:v[i])
                {
                    if(!odw[x]&&xd[x]<m/2+m%2)
                    {
                        xd[x]++;
                        ans[i]=x;
                        emp--;
                        break;
                    }
                }
            }
        }
        if(emp==0)
        {
            cout<<"YES"<<endl;
            for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
            cout<<endl;
        }
        else cout<<"NO"<<endl;
        for(int i=0;i<=max(m,n);i++)
        {
            ans[i]=0;
            v[i].clear();
            v1[i].clear();
            cnt[i]=0;
            odw[i]=0;
            xd[i]=0;
        }
    }

    return 0;
}