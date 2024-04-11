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

int a[200007];
int l[200007];
int r[200007];
bool nie[200007];
int DP[200007];
int id[200007];

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
        vector<pair<int,int>>vec;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            a[i]+=1000000000;
            vec.pb({a[i],0});
        }
        for(int i=1;i<=m;i++)
        {
            cin>>l[i]>>r[i];
            l[i]+=1000000000;
            r[i]+=1000000000;
            vec.pb({l[i],-i});
            vec.pb({r[i],i});
            nie[i]=0;
            DP[i]=0;
        }
        sort(all(vec));
        set<pair<int,int>>act;
        for(auto x:vec)
        {
            if(x.nd<0) act.insert({l[-x.nd],-x.nd});
            else if(x.nd==0)
            {
                for(auto y:act) nie[y.nd]=1;
                act.clear();
            }
            else
            {
                act.erase({l[x.nd],x.nd});
                while(sz(act)>0)
                {
                    pair<int,int>p=*act.begin();
                    if(p.st>l[x.nd]) break;
                    nie[p.nd]=1;
                    act.erase(p);
                }
            }
        }
        int it=0;
        int p1=inf,p2=inf,c1=inf,c2=inf;
        int pos=-inf;
        for(auto x:vec)
        {
            if(nie[abs(x.nd)]) continue;
            if(x.nd==0)
            {
                p1=min(DP[it+1],c2+2*x.st);
                p2=min(DP[it+1],c1+x.st);
                DP[it+1]=min(DP[it+1],min(p1,p2));
                pos=x.st;
            }
            else if(x.nd<0)
            {
                it++;
                id[-x.nd]=it;
                DP[it+1]=min(p1+x.st-pos,p2+2*(x.st-pos));
            }
            else
            {
                c1=min(c1,DP[id[x.nd]]-x.st);
                c2=min(c2,DP[id[x.nd]]-2*x.st);
            }
        }
        cout<<DP[it+1]<<endl;
    }

    return 0;
}