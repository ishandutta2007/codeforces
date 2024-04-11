#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
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

int P[300007];
vector<int>ans[300007];
vector<pair<int,int>>Q[300007][2];
unordered_map<int,int>last[2];

string s;

int val(int l,int i)
{
    if((i%2)^(!(l%2)))
    {
        if(s[i]=='+') return 1;
        else return -1;
    }
    else
    {
        if(s[i]=='+') return -1;
        else return 1;
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
        int n,q,l,r;
        cin>>n>>q;
        cin>>s;
        s='#'+s;
        for(int i=1;i<=n;i++) P[i]=P[i-1]+val(1,i);
       // for(int i=1;i<=n;i++) cout<<P[i]<<" ";
      //  cout<<endl;
        for(int i=1;i<=q;i++)
        {
            cin>>l>>r;
            int d=P[r]-P[l-1];
            if(l%2==0) d=-d;
            if(d==0) continue;
            if((r-l+1)%2==0)
            {
                ans[i].pb(r);
                d-=val(l,r);
                r--;
            }

            if(d>0) Q[r][l%2].pb({d/2+1,i});
            else Q[r][l%2].pb({d/2-1,i});
        }
        last[0].clear();
        last[1].clear();
        for(int i=1;i<=n;i++)
        {
            for(auto x:Q[i][0]) ans[x.nd].pb(last[0][-P[i]-x.st]+1);
            for(auto x:Q[i][1]) ans[x.nd].pb(last[1][P[i]-x.st]+1);
            Q[i][0].clear();
            Q[i][1].clear();
            last[1][P[i]]=i;
            last[0][-P[i]]=i;
        }
        for(int i=1;i<=q;i++)
        {
            cout<<sz(ans[i])<<endl;
            for(auto x:ans[i]) cout<<x<<" ";
            cout<<endl;
            ans[i].clear();
        }
    }

    return 0;
}