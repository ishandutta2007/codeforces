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

const bool multi=0;

int id[200];
vector<int>G[407];
bool tak[407];
vector<int>V;
char c[207][2];
int n;

void mark(int v)
{
    if(tak[v]) return ;
    tak[v]=1;
    V.pb(v);
    for(auto u:G[v]) if(!tak[u]) mark(u);
}
string ans,l,s;
void solve(int k)
{
    memset(tak,0,sizeof tak);
    for(int i=0;i<n;i++)
    {
        c[i][0]=0,c[i][1]=0;
        int j=0,z=sz(l);
        if(i<k)
        {
            j=s[i]-'a';
            z=s[i]-'a'+1;
        }
        else if(i==k) j=s[i]-'a'+1;
        for(;j<z;j++) if(c[i][id[l[j]]]==0) c[i][id[l[j]]]=j+'a';
       // cout<<c[i][0]<<" "<<c[i][1]<<endl;
        for(int p=0;p<2;p++) if(!c[i][p]) mark((2*(i+1))^(p^1));
    }
    string act="";
    for(int i=0;i<n;i++)
    {
        vector<int>v;
        bool is=0;
        if(c[i][0]<c[i][1]) v={0,1};
        else v={1,0};
        for(auto p:v)
        {
            V.clear();
            mark((2*(i+1))^p);
            if(!tak[(2*(i+1))^(p^1)])
            {
                is=1;
                act+=c[i][p];
                break;
            }
            for(auto x:V) tak[x]=0;
        }
        if(!is) return ;
    }
    ans=min(ans,act);
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
        id['V']=0,id['C']=1;
        int m;
        cin>>l>>n>>m;
        while(m--)
        {
            int x,y;
            char a,b;
            cin>>x>>a>>y>>b;
            G[(2*x)^id[a]].pb((2*y)^id[b]);
            G[(2*y)^(!id[b])].pb((2*x)^(!id[a]));
        }
        cin>>s;
        for(int i=1;i<=2*n;i++) ans+=(char)('z'+7);
        for(int i=0;i<=n;i++) solve(i);
        if(sz(ans)==2*n) cout<<-1;
        else cout<<ans;
    }

    return 0;
}