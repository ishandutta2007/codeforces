#include <bits/stdc++.h>
using namespace std;
 
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()

const int L = 4000;

//CHT structure : 
struct line {
    long long m, c;
    long long eval(long long x) { return m * x + c; }
    long double intersectX(line l) { return (long double) (c - l.c) / (l.m - m); }
};

const int MOD = 1e9+7;
const int N = 2004;

vector<pii> g[N];
vector<int> cur(N),nex(N);

const int inf = 1e18;

vector<pii> go;

int calc(line ln,int x1,int x2)
{
    ln.m %= MOD;
    ln.c %= MOD;
    
    int fix = (ln.c + (ln.m*x1));
    fix %= MOD;
    
    int res = (fix*(x2 - x1 + 1));
    res %= MOD;
    
    int s1 = (x2 - x1);
    int s2 = (s1*(s1 + 1))/2;
    
    s2 %= MOD;
    
    res += (ln.m*s2);
    
    res %= MOD;
    
    return res;
}

void solve()
{
   int n,m,q;
    cin>> n >> m >> q;
    
   int u,v,w;
    
   f(i,m)
   {
       cin >> u >> v >> w;
       g[u].pb({v,w});
       g[v].pb({u,w});
   }
   
   for(int i=2;i<=n;i++) cur[i] = -inf;
   cur[1] = 0; 
    
   int res = 0;

   for(int i=1;i<=min(q,L);i++)
   {
       for(int j=1;j<=n;j++) nex[j] = -inf;
       
       for(int j=1;j<=n;j++)
         for(auto x : g[j])
           nex[x.F] = max(nex[x.F],cur[j] + x.S);
         
       swap(cur,nex);
       
       res += *max_element(all(cur));
       res %= MOD;
   }           
    
   if(q > L)
   {
       //create Convex Hull
       deque<line> dq;
       dq.push_front({0, 0});
       
       for(int i=1;i<=n;i++)
         for(auto x : g[i])
           go.pb({x.S,cur[i] - (x.S*L)});
       
       sort(all(go));
       
       auto go2 = go;
       go.clear();
       
       for(auto x : go2)
       {
           if(go.empty()) go.pb(x);
           else if(go.back().F == x.F)
           {
               go.back() = x;
           }
           else go.pb(x);
       }
       
       for(auto x : go)
       {
          line cur = {x.F,x.S};
          while (dq.size() >= 2 && cur.intersectX(dq[0]) <= dq[0].intersectX(dq[1])) dq.pop_front();
          dq.push_front(cur);
       }
       
       int st = L + 1;
       
       while(st <= q && !dq.empty())
       {
           auto z1 = dq.back(); dq.pop_back();
           
           if(dq.empty())
           {
               res += calc(z1,st,q);
               res %= MOD;
               break;
           }
           
           auto z2 = dq.back();
           
           if(z1.m == z2.m) continue;
           
           double interX = (z1.c - z2.c)/(z2.m - z1.m);
           
           int R = min(q,(int)floor(interX));
           
           if(R >= st)
           {
               res += calc(z1,st,R);
               res %= MOD;
               st = R + 1;
           }
       }
   }
   
   cout << res;
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}