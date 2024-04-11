#include <bits/stdc++.h>
using namespace std;

#define INF 1000000007

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vector<pair<int,int> > > vvii;

#define all(x) x.begin(), x.end()
#define tr(x,it) for(auto it = x.begin();it!=x.end();++it)
#define ntr(x,it) for(auto it = x.rbegin();it!=x.rend();++it)
#define sz(a) int((a).size()) 
#define pb push_back 
#define PB pop_back
#define pf push_front
#define PF pop_front
#define MP make_pair
#define clr clear
#define rz resize
#define C(a,b) memset(a,b,sizeof(a))
#define ia(a,n) FOR(i,0,n-1)cin>>a[i]
#define fpresent(c,x) ((c).find(x) != (c).end())  // set,map
#define present(c,x) (find(all(c),x) != (c).end())  //vector
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define NFOR(i,a,b) for(int i=a;i>=b;--i)
#define rep(i,n) FOR(i,0,n-1)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)


vi g[50001];
int n,k;
int d[50001][501];
void dfs(int v,int p=-1)
{
    d[v][0]=1;
    tr(g[v],it)
    {
        if(*it==p)continue;
        
        dfs(*it,v);
        FOR(i,1,k)
        d[v][i]+=d[*it][i-1];
    }
}
int temp[501];
void DFS(int v,int p=-1)
{
    FOR(i,0,k)temp[i]=d[v][i];
    if(p!=-1)
    {
        FOR(i,1,k)
        {
            if(i==1)d[v][i]+=1;
            else
            d[v][i]+=d[p][i-1]-temp[i-2];
        }
    }
    tr(g[v],it)
    {
        if(*it==p)continue;
        DFS(*it,v);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    
    cin>>n>>k;
    
    FOR(i,1,n-1){int a,b;cin>>a>>b;--a,--b;g[a].pb(b);g[b].pb(a);}
    
    
    
    dfs(0);
    DFS(0);
    ll ans=0;
    FOR(i,0,n-1)ans+=d[i][k];
    ans>>=1;
    cout<<ans;
    return 0;
}