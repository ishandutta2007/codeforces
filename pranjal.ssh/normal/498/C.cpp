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
inline int neg(int x,int m=INF){x=-x;return norm(x);}
inline int norm(int x,int m=INF){if(x>=m)x%=m;if(x<0)x+=m;return x;}

struct Flow
{
    vvi G;
    vvi cap;
    vi from;
    vector<bool>vis;
    int Source,Sink;
    Flow(int n)
    {
        G.rz(n+2);
        Source=0;
        Sink=n+1;
        cap.rz(n+2);
        FOR(i,0,n+1)cap[i].rz(n+2);
        from.rz(n+2);
        vis.rz(n+2);
    }
    void Add(int u, int v, int c, bool dir=1)
    {
        G[u].pb(v);
        G[v].pb(u);
        cap[u][v]=c;
        if(dir==0)cap[v][u]=c;
    }
    int bfs()
    {
        fill(all(from),-1);
        fill(all(vis),0);
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
};

vvii a;
vi pos;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int n,m;
    cin>>n>>m;
    a.rz(n);
    pos.rz(n);
    pos[0]=1;
    FOR(i,0,n-1)
    {
        int x;
        cin>>x;
        int y=x;
        FOR(j,2,31622)
        {
            int ctr=0;
            while(x%j==0)
            x/=j,ctr++;
            if(ctr)a[i].pb({j,ctr});
        }
        if(x>1)a[i].pb({x,1});
        if(i)pos[i]=pos[i-1]+a[i-1].size();
    }
    Flow FF(pos[n-1]+a[n-1].size()-1);
    FOR(i,0,n-1)
    {
        if(!(i&1))
        tr(a[i],it)
        FF.Add(FF.Source,pos[i]+(it-a[i].begin()),it->S);
        else
        tr(a[i],it)
        FF.Add(pos[i]+(it-a[i].begin()),FF.Sink,it->S);
    }
    while(m--)
    {
        int i,j;
        cin>>i>>j;
        --i,--j;
        if(i&1)
        swap(i,j);
        tr(a[i],it)
        {
            tr(a[j],it2)
            {
                if(it2->F==it->F)
                FF.Add(pos[i]+(it-a[i].begin()),pos[j]+(it2-a[j].begin()),100);
            }
        }
    }
   
    cout<<FF.max_flow();
    return 0;
}