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
#define tr(x,it) for(auto it = (x).begin();it!=(x).end();++it)
#define ntr(x,it) for(auto it = (x).rbegin();it!=(x).rend();++it)
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
int expo(int a,int d,int m)
{
    if(d==0)
    return 1;
    long long ans=expo(a,d/2,m);
    ans=(ans*ans)%m;
    if(d&1)
    return (ans*a)%m;
    return ans;
}
bool isPrime(int n)
{
  if(n==1)
  return false;
  if(n==2||n==3||n==7||n==61)
  return true;
  int r=0,d=n-1;
  while(!(d&1))
  {
    r++;
    d>>=1;
  }
  vector<int> a(3);
  a[0]=2;
  a[1]=7;
  a[2]=61;
  for(int i=0;i<a.size();i++)
  {
    long long x=expo(a[i],d,n);
    if(x==1||x==n-1)
    continue;
    for(int j=1;j<r;j++)
    {
      x=(x*x)%n;
      if(x==1)
        return false;
      if(x==n-1)
        break;
    }
    if(x==n-1)
    continue;
    else
    return false;
  }
  return true;
}
const int maxn=202;
vector<int> G[maxn];
int cap[maxn][maxn];
int from[maxn];
bool vis[maxn];
int a[maxn];
int Source,Sink;
int bfs()
{
    fill(from,from+Sink+1,-1);
    fill(vis,vis+Sink+1,0);
    queue<int> q;
    q.push(Source);
    vis[Source]=1;
    int u;
    while(!q.empty())
    {
        u=q.front();q.pop();
        //if(u==g+h+1)break;
        tr(G[u],it)
        {
            if((!vis[*it])&&(cap[u][*it]>0))
            {from[*it]=u;q.push(*it);vis[*it]=1;}
        }
    }
    int mn=INF;u=Sink;
    while(from[u]!=-1)
    {
        mn=min(mn,cap[from[u]][u]);
        u=from[u];
    }
    u=Sink;
    while(from[u]!=-1)
    {
        cap[from[u]][u]-=mn;
        cap[u][from[u]]+=mn;
        u=from[u];
    }
    mn=(mn==INF)?0:mn;
    return mn;
}

int max_flow(){int ans=0;int temp;while(1){temp=bfs();if(temp==0)break;ans+=temp;}return ans;}
vi even,odd;
vvi ans;


map<int,vi> mp;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    FOR(i,0,n-1){cin>>a[i];(a[i]&1)?odd.pb(a[i]):even.pb(a[i]);mp[a[i]].pb(i+1);}
    if(even.size()!=odd.size())
    {
        cout<<"Impossible";return 0;
    }
    int x=even.size();
    
    Source=0;
    Sink=2*x+1;
    FOR(i,0,x-1)
    {
        G[Source].pb(1+i);
        cap[Source][1+i]=2;
        G[1+i].pb(Source);
        G[1+i+x].pb(Sink);
        cap[1+i+x][Sink]=2;
        G[Sink].pb(1+i+x);
    }
    FOR(i,0,x-1)
    {
        FOR(j,0,x-1)
        {
            if(isPrime(even[i] + odd[j]))
            {
                G[1+i].pb(1+j+x);
                G[1+j+x].pb(1+i);
                cap[1+i][1+j+x]=1;
                //cap[1+j+x][1+i]=1;
            }
        }
    }
    int xx=max_flow();
    
    // FOR(i,0,2*x+1)
    // {
    //  FOR(j,0,2*x+1)
    //  cout<<cap[i][j]<<" ";
    //  cout<<endl;
    // }
    if(xx==2*x)
    {
        
        vector<bool> vis(2*x+2);
        vis[0]=vis[2*x+1]=1;
        
        FOR(i,1,x)
        {
            if(vis[i])continue;
            vis[i]=1;
            vi now;
            int j=i;
            bool cc=1;
            do
            {
                
                    now.pb(j);
                
                
                    FOR(k,x+1,2*x)
                    if(vis[k]==0 and cap[k][j]==1)
                    {j=k;vis[j]=1;break;}
   
                    now.pb(j);
                    
                    FOR(k,1,x)
                    if(vis[k]==0 and cap[j][k]==1)
                    {j=k;vis[j]=1;break;}
                    
                    if(cc)vis[i]=0,cc=0;
                
            }while(j!=i);
            ans.pb(now);
            
        }
            cout<<ans.size()<<"\n";
            tr(ans,it)
            {
                vi now=*it;
                int xxx=now.size();
                cout<<xxx<<" ";
                FOR(i,0,xxx-1)
                {
                    if(!(i&1))
                    {cout<<mp[even[now[i]-1]].back()<<" ";mp[even[now[i]-1]].pop_back();}
                    else
                    {cout<<mp[odd[now[i]-1-x]].back()<<" ";mp[odd[now[i]-1-x]].pop_back();}
                }
                cout<<"\n";
            }
        
    }
    else
    {
        cout<<"Impossible";
    }
    
    return 0;
}