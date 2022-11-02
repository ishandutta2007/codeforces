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

const int N=100007;

set<pair<int,int>>akt[N];
int o[N];

int Find(int v)
{
    if(o[v]==v) return v;
    return o[v]=Find(o[v]);
}
void Union(int v,int u)
{
    if(u==v) return ;
   // cout<<u<<" "<<v<<endl;
    o[v]=u;
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
        for(int i=1;i<=n;i++) o[i]=i;
        vector<pair<pair<int,int>,pair<int,int>>>V;
        for(int i=1;i<=n;i++)
        {
            int l,r,c;
            cin>>c>>l>>r;
            V.pb({{l,-i},{c,r}});
            V.pb({{r,i},{c,l}});
        }
        sort(all(V));
        for(auto x:V)
        {
            if(x.st.nd<0) akt[x.nd.st].insert({x.nd.nd,-x.st.nd});
            else
            {
                if(sz(akt[0])>0&&sz(akt[1])>0)
                {
                    while(sz(akt[0])>1)
                    {
                        Union(Find((*akt[0].begin()).nd),Find((*--akt[0].end()).nd));
                        akt[0].erase(akt[0].begin());
                    }
                    while(sz(akt[1])>1)
                    {
                        Union(Find((*akt[1].begin()).nd),Find((*--akt[1].end()).nd));
                        akt[1].erase(akt[1].begin());
                    }
                    Union(Find((*akt[0].begin()).nd),Find((*akt[1].begin()).nd));
                }
                akt[x.nd.st].erase(x.st);
            }
        }
        set<int>S;
        for(int i=1;i<=n;i++) S.insert(Find(i));
        cout<<sz(S)<<endl;
    }

    return 0;
}