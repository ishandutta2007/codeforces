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

vector<int> pos[100007];
bool is[100007];
int a[100007];
int b[100007];

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
        int n,x,y;
        cin>>n>>x>>y;
        for(int i=1;i<=n+1;i++) pos[i].clear();
        memset(is,0,sizeof is);
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            pos[a[i]].pb(i);
        }
        int missing=-1;
        for(int i=1;i<=n+1;i++) if(sz(pos[i])==0) missing=i;
        set<pair<int,int>>Q;
        for(int i=1;i<=n+1;i++) Q.insert({sz(pos[i]),i});
        for(int i=0;i<x;i++)
        {
            pair<int,int>p=*(--Q.end());
            Q.erase(p);
            b[pos[p.nd].back()]=p.nd;
            is[pos[p.nd].back()]=1;
            pos[p.nd].pop_back();
            p.st--;
            Q.insert(p);
        }
        pair<int,int>p=*(--Q.end());
        if(2*p.st-(n-x)>n-y)
        {
            cout<<"NO"<<endl;
            continue;
        }
        vector<int>v;
        for(int i=1;i<=n+1;i++) for(auto j:pos[i]) v.pb(j);
        for(int i=0;i<sz(v);i++) b[v[(i+p.st)%sz(v)]]=a[v[i]];
        int ay=n;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==b[i]&&!is[i])
            {
                b[i]=missing;
                ay--;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(is[i]||b[i]==missing||ay==y) continue;
            b[i]=missing;
            ay--;
        }
        cout<<"YES"<<endl;
        for(int i=1;i<=n;i++) cout<<b[i]<<" ";
        cout<<endl;
    }

    return 0;
}