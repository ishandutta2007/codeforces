#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXK=65;
const int MAXN=2005;
const int Mod=1000000007;
int dp[MAXK][6];
void build()
{
    for(int j=0;j<6;j++)
        dp[1][j]=1;
    for(int i=1;i<MAXK;i++)
        for(int j=0;j<6;j++)
            for(int p=0;p<6;p++)
                for(int q=0;q<6;q++)
                    if(j!=p && j!=q && j!=(p+3)%6 && j!=(q+3)%6)
                        dp[i][j]=(dp[i][j]+1LL*dp[i-1][p]*dp[i-1][q])%Mod;
}
map<ll,int> mp;
inline int get_id(ll n)
{
    int& id=mp[n];
    if(!id)id=mp.size();
    return id;
}
struct node
{
    int l,r,c,h;
    node():l(0),r(0),c(-1),h(-1){}
}tree[MAXN*MAXK];
int res[MAXN*MAXK][6];
void dfs(int u)
{
    if(!u)return;
    if(!tree[u].l && !tree[u].r)
    {
        int l=(tree[u].c<0 ? 0 : tree[u].c),r=(tree[u].c<0 ? 5 : tree[u].c);
        for(int i=l;i<=r;i++)
            res[u][i]=dp[tree[u].h][i];
        return;
    }
    dfs(tree[u].l);
    dfs(tree[u].r);
    int *dp_lef=(tree[u].l ? res[tree[u].l] : dp[tree[u].h-1]);
    int *dp_rig=(tree[u].r ? res[tree[u].r] : dp[tree[u].h-1]);
    int l=(tree[u].c<0 ? 0 : tree[u].c),r=(tree[u].c<0 ? 5 : tree[u].c);
    for(int j=l;j<=r;j++)
        for(int p=0;p<6;p++)
            for(int q=0;q<6;q++)
                if(j!=p && j!=q && j!=(p+3)%6 && j!=(q+3)%6)
                    res[u][j]=(res[u][j]+1LL*dp_lef[p]*dp_rig[q])%Mod;
}
int main()
{
    build();
    int k,n;
    scanf("%d%d",&k,&n);
    for(int i=1;i<=n;i++)
    {
        ll v;
        int c=-1;
        char str[15];
        scanf("%lld%s",&v,str);
        if(str[0]=='w')c=0;
        if(str[0]=='y')c=3;
        if(str[0]=='g')c=1;
        if(str[0]=='b')c=4;
        if(str[0]=='r')c=2;
        if(str[0]=='o')c=5;
        tree[get_id(v)].c=c;
        vector<ll> path;
        while(v>0)path.push_back(v),v>>=1;
        for(int i=(int)path.size()-1,h=k;i>=0;i--,h--)
            tree[get_id(path[i])].h=h;
        for(int i=0;i+1<(int)path.size();i++)
        {
            if(path[i]&1)tree[get_id(path[i+1])].l=get_id(path[i]);
            else tree[get_id(path[i+1])].r=get_id(path[i]);
        }
    }
    int root=get_id(1),ans=0;
    dfs(root);
    for(int j=0;j<6;j++)
        ans=(ans+res[root][j])%Mod;
    return 0*printf("%d\n",ans);
}