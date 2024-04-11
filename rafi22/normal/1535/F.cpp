#include <bits/stdc++.h>

#define int long long
#define double long double
//#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

string s[200007];
string s1[200007];
int it=1,n,m;
int fen[400007];
int trie[200007][27];
int pre[200007],post[200007],c=0;
int last[27];

void dfs(int v)
{
    pre[v]=++c;
    for(int j=0;j<26;j++) if(trie[v][j]>0) dfs(trie[v][j]);
    post[v]=c;
}

inline void ins(int x,int val) {while(x<=it)  {  fen[x]+=val;  x+=(x&-x);  } }

inline int que(int x) {int res=0;  while(x>0)  {  res+=fen[x];  x-=(x&-x);  } return res; }

vector<int> gdzie[200007];
vector<int> mx[200007];
int pairs;

void solve(vector<int> id,int j)
{
    if(sz(id)<=1||j>=m) return ;
    for(auto x:id) ins(pre[gdzie[x][0]],1);
    vector<int>vec[26];
    for(auto x:id) vec[s[x][j]-'a'].pb(x);
    for(int i=0;i<26;i++)
    {
        for(auto x:vec[i]) ins(pre[gdzie[x][0]],-1);
        for(auto x:vec[i]) pairs+=que(post[gdzie[x][mx[x][j]]])-que(pre[gdzie[x][mx[x][j]]]-1);
        for(auto x:vec[i]) ins(pre[gdzie[x][0]],1);
    }
    for(auto x:id) ins(pre[gdzie[x][0]],-1);
    for(int i=0;i<26;i++) solve(vec[i],j+1);
}

map<string,int>mapa;

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
        cin>>n;
        for(int i=1;i<=n;i++) cin>>s[i];
        m=sz(s[1]);
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=m+1;j++)
            {
                gdzie[i].pb(0);
                mx[i].pb(0);
            }
            int p=1;
            gdzie[i][m]=1;
            for(int j=m-1;j>=0;j--)
            {
                if(trie[p][s[i][j]-'a']==0) trie[p][s[i][j]-'a']=++it;
                p=trie[p][s[i][j]-'a'];
                gdzie[i][j]=p;
            }
        }
        dfs(1);
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<26;j++) last[j]=m;
            mx[i][m]=m;
            for(int j=m-1;j>=0;j--)
            {
                int xd=mod;
                last[s[i][j]-'a']=j;
                for(int l=s[i][j]-'a'-1;l>=0;l--) xd=min(xd,last[l]);
                mx[i][j]=min(xd,mx[i][j+1]);
            }
        }
        vector<int>act;
        for(int i=1;i<=n;i++)
        {
            s1[i]=s[i];
            sort(s1[i].begin(),s1[i].end());
        }
        vector<pair<string,int>>vec;
        for(int i=1;i<=n;i++) vec.pb({s1[i],i});
        sort(vec.begin(),vec.end());
        act.pb(vec[0].nd);
        int ans=0,bad=0,good=0;
        for(int i=1;i<=n;i++)
        {
            good+=mapa[s[i]];
            mapa[s[i]]++;
        }
        for(int i=1;i<n;i++)
        {
            if(vec[i].st!=vec[i-1].st)
            {
                pairs=0;
                solve(act,0);
                ans+=pairs;
                ans+=2*(sz(act)*(sz(act)-1)/2-pairs);
                bad+=sz(act)*(n-sz(act));
                act.clear();
            }
            act.pb(vec[i].nd);
        }
        pairs=0;
        solve(act,0);
        ans+=pairs;
        ans+=2*(sz(act)*(sz(act)-1)/2-pairs);
        bad+=sz(act)*(n-sz(act));
        ans+=bad/2*1337;
        ans-=good*2;
        cout<<ans<<endl;
    }

    return 0;
}