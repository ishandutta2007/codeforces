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
int pos[200007];
int r[200007];
int mn[200007];

int Find(int v)
{
    if(r[v]==v) return v;
    return r[v]=Find(r[v]);
}
set<int>S;
void Union(int u,int v)
{
    if(v<u) swap(v,u);
    if(u==v) return ;
    mn[u]=min(mn[u],mn[v]);
    r[v]=u;
    S.erase(v);
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
        S.clear();
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            pos[a[i]]=i;
            S.insert(i);
            mn[i]=a[i];
        }
        S.insert(inf);
        for(int i=1;i<=n;i++) r[i]=i;
        for(int i=n;i>0;i--)
        {
            while(true)
            {
                int x=*S.upper_bound(pos[i]);
                if(x==inf) break;
                Union(Find(pos[i]),Find(x));
            }
            if(Find(pos[i])!=pos[i]) S.erase(pos[i]);
            if(mn[Find(pos[i])]==i) S.erase(Find(pos[i]));
        }
        set<int>D;
        for(int i=1;i<=n;i++) D.insert(Find(i));
        cout<<sz(D)<<endl;
    }

    return 0;
}