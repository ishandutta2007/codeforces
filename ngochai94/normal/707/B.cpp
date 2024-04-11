#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define off 250555

int n,m,ans,u,v,c,k,lis[100005];
vector<pair<int,int> > adj[100005];

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d %d %d", &n, &m, &k);
    For(i,0,m)
    {
        scanf("%d %d %d", &u, &v, &c);
        adj[u].pb({v,c});
        adj[v].pb({u,c});
    }
    For(i,0,k)
    {
        scanf("%d", &u);
        lis[u]=1;
    }
    ans=mod;
    For(i,1,n+1) if(lis[i])
    {
        //cout<<i<<endl;
        for(auto p:adj[i]) if(!lis[p.first]) ans=min(ans,p.second);
    }
    if(ans==mod) cout<<-1;
    else cout<<ans;
}