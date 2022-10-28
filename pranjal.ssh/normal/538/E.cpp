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

#define all(x) (x).begin(), (x).end()
#define nall(x) (x).rbegin(), (x).rend()
#define tr(x,it) for(auto it = (x).begin();it!=(x).end();++it)
#define ntr(x,it) for(auto it = (x).rbegin();it!=(x).rend();++it)
#define ufy(v) sort(all(v));(v).erase(unique(all((v))),(v).end())
#define sz(a) int((a).size()) 
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back 
#define PB pop_back
#define pf push_front
#define PF pop_front
#define MP make_pair
#define clr clear
#define rz resize
#define C(a,b) memset(a,b,sizeof(a))
#define ia(a,n) FOR(i,0,n-1)cin>>a[i]
#define ia1(a,n) FOR(i,1,n)cin>>a[i]
#define fpresent(c,x) ((c).find(x) != (c).end())  // set,map
#define present(c,x) (find(all(c),x) != (c).end())  //vector
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define NFOR(i,a,b) for(int i=a;i>=b;--i)
#define rep(i,n) FOR(i,0,n-1)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)
inline int add(int a,int b, int m=INF){a+=b;if(a>=m)a-=m;return a;}
inline int mul(int a,int b, int m=INF){return (int)(((ll)a*(ll)b)%m);}
inline int norm(int x,int m=INF){if(x>=m)x%=m;if(x<0)x+=m;return x;}
inline int neg(int x,int m=INF){x=-x;return norm(x);}

const int N=2e5+10;

vi g[N];
int dp[2][N];
int sub[N];
void dfs(int u,bool t,int p=-1)
{
    sub[u]=sz(g[u])==1 and p!=-1;
    if(sub[u]==1)
    {
        dp[0][u]=1;
        dp[1][u]=1;
        return;
    }
    if(!t)
    {
        tr(g[u],it)
        {
            if(*it==p)continue;
            dfs(*it,!t,u);
            sub[u]+=sub[*it];
        }
        dp[0][u]=sub[u];
        dp[1][u]=0;
        tr(g[u],it)
        {
            if(*it==p)continue;
            dp[0][u]=min(dp[0][u],dp[0][*it]);
            dp[1][u]+=dp[1][*it];
        }
    }
    else
    {
        tr(g[u],it)
        {
            if(*it==p)continue;
            dfs(*it,!t,u);
            sub[u]+=sub[*it];
        }

        dp[0][u]=0;
        dp[1][u]=sub[u];
        tr(g[u],it)
        {
            if(*it==p)continue;
            dp[0][u]+=dp[0][*it];
            dp[1][u]=min(dp[1][u],dp[1][*it]);
        }
    }
    
}

int main()
{
    boost;
    int n;
    cin>>n;
    int m=n-1;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        g[x].pb(y),g[y].pb(x);
    }

    dfs(1,0);
    cout<<sub[1]-dp[0][1]+1<<" "<<max(1,dp[1][1]);


    return 0;
}