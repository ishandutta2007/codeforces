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

string ans,S;
int l[200007];
int r[200007];
int id[200007];
char z[200007];
bool tak[200007];
int nx[200007];
int last[26];
int n,k;
int it=0;
void dfs(int v)
{
    if(l[v]!=0) dfs(l[v]);
    id[v]=++it;
    z[it]=S[v];
    if(r[v]!=0) dfs(r[v]);
}

bool dfs1(int v)
{
    if(k<=0) return 0;
    k--;
    if(l[v]!=0&&dfs1(l[v])) tak[v]=1;
    if(nx[id[v]]!=inf&&z[nx[id[v]]]>z[id[v]]) tak[v]=1;
    if(r[v]!=0&&tak[v]) dfs1(r[v]);
    if(!tak[v]) k++;
    return tak[v];
}
void dfs2(int v)
{
    if(l[v]!=0) dfs2(l[v]);
    ans+=z[id[v]];
    if(tak[v]) ans+=z[id[v]];
    if(r[v]!=0) dfs2(r[v]);
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
        cin>>n>>k>>S;
        S='#'+S;
        for(int i=1;i<=n;i++) cin>>l[i]>>r[i];
        dfs(1);
        for(int i=0;i<26;i++) last[i]=inf;
        for(int i=n;i>0;i--)
        {
            nx[i]=inf;
            for(int j=0;j<26;j++)
            {
                if(j==z[i]-'a') continue;
                nx[i]=min(nx[i],last[j]);
            }
            last[z[i]-'a']=i;
        }
        dfs1(1);
        dfs2(1);
        cout<<ans;
    }

    return 0;
}