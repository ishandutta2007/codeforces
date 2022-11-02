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

const int N=400007;
int a[N];
int z[N];
int r[3*N];
int w[3*N];

int Find(int v)
{
    if(r[v]==v) return v;
    return r[v]=Find(r[v]);
}
void Union(int v,int u)
{
    v=Find(v),u=Find(u);
    if(v==u) return ;
    r[v]=u;
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
        set<pair<int,int>>X;
        X.insert({inf,0});
        X.insert({-inf,0});
        int c=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            c++;
            z[i]=c;
            w[c]=a[i];
            r[c]=c;
            X.insert({a[i],c});
        }
        int q;
        cin>>q;
        while(q--)
        {
            int t,x,y;
            cin>>t;
            if(t==1)
            {
                cin>>x>>y;
                c++;
                z[x]=c;
                w[c]=y;
                r[c]=c;
                X.insert({y,c});
            }
            if(t==2)
            {
                cin>>x;
                cout<<w[Find(z[x])]<<endl;
            }
            if(t==3)
            {
                cin>>x>>y;
                vector<int>V,V1;
                while(true)
                {
                    pair<int,int>p=*X.lower_bound({x,0});
                    if(p.st>y) break;
                    X.erase(p);
                    if(p.st<=(x+y)/2) V.pb(p.nd);
                    else V1.pb(p.nd);
                }
                c++;
                w[c]=x-1;
                r[c]=c;
                X.insert({x-1,c});
                for(auto i:V) Union(i,c);
                c++;
                w[c]=y+1;
                r[c]=c;
                X.insert({y+1,c});
                for(auto i:V1) Union(i,c);
            }
        }
    }

    return 0;
}