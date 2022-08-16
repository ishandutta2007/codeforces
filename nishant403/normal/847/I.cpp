//AUTHOR : TIRTH JARSANIA
//COLLEGE : DAIICT

#include<bits/stdc++.h>
using namespace std;

#define INF LONG_LONG_MAX
#define MINF LONG_LONG_MIN
#define bp __builtin_popcountll
#define ll long long int
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<ll,ll>
#define precision(x,d) cout<<fixed<<setprecision(d)<<x
#define minQueue priority_queue<pii,vector<pii>,greater<pii> > 
#define maxQueue priority_queue<pii> 
#define FAST ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);srand(time(NULL))
#define L(p) 2*p+1
#define R(p) 2*p+2

const ll N = 250;
ll dp[N][N];
bool vis[N][N];
ll dis[N][N];
vector<string> s(N);
ll n , m , q, p;
bool check(ll x,ll y)
{
    if(x>=0 && x<n && y>=0 && y<m)
        return 1;
    return 0;
}

int main()
{
    FAST;
    cin >> n >> m >> q >> p;
    for(ll i= 0 ; i <  n ; i++ ) cin >> s[i];
    vector<ll> a(26,0);
    ll b = 0;
    ll c = 1;
    for(ll i = 0 ; i  < 26 ; i++ )
    {
        ll x = q*(i+1);
        while( c <= x)
        {
            c*=2;
            b++;
        }
        c/=2;
        b--;
        a[i] = b;
        
    }
    for(ll ii=0;ii<n;ii++)
    {
        for(ll jj=0;jj<m;jj++)
        {
            if(s[ii][jj]!='.' && s[ii][jj] != '*')
            {
                
                ll x = s[ii][jj]-'A';
                
                
                memset(vis,0,sizeof(vis));
                memset(dis,0,sizeof(dis));
                vis[ii][jj] = 1;
                queue<pii> Q;
                Q.push({ii,jj});
                while(!Q.empty())
                {
                    pii A = Q.front();
                    Q.pop();
                    ll i = A.ff;
                    ll j = A.ss;
                    if(dis[i][j] <= a[x]){ dp[i][j] += (q*(s[ii][jj]-'A'+1))/pow(2, dis[i][j]);
                    if( check(i+1,j) && !vis[i+1][j] && s[i+1][j] != '*') 
                    {
                        
                        dis[i+1][j] = dis[A.ff][A.ss] + 1;
                        Q.push({i+1,j});
                        vis[i+1][j] = 1;
                    }
                    if( check(i-1,j) && !vis[i-1][j] && s[i-1][j] != '*') 
                    {
                        
                        dis[i-1][j] = dis[A.ff][A.ss] + 1;
                        Q.push({i-1,j});
                        vis[i-1][j] = 1;
                    }
                    if( check(i,j-1) && !vis[i][j-1] && s[i][j-1] != '*') 
                    {
                        
                        dis[i][j-1] = dis[A.ff][A.ss] + 1;
                        Q.push({i,j-1});
                        vis[i][j-1] = 1;
                    }
                    if(check(i,j+1) && !vis[i][j+1] && s[i][j+1] != '*' ) 
                    {
                        
                        dis[i][j+1] = dis[A.ff][A.ss] + 1;
                        Q.push({i,j+1});
                        vis[i][j+1] = 1;
                    }
                                         }}
              
            }
        }
    }
    ll ans = 0;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            if(dp[i][j] >p)
                ans++;
        }
    }
    cout << ans;
}