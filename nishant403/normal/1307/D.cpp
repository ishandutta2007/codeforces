#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = 2e5+10;
const int INF = N;
vi g[N];
int n;
int d1[N];
int d2[N];

void go()
{
    
for(int i=1;i<=n;i++) d1[i] = INF;  
    
int s = 1;   
    
d1[s] = 0;
deque<int> q;
q.push_front(s);
while (!q.empty()) {
    int v = q.front();
    q.pop_front();
    for (auto edge : g[v]) {
        int u = edge;
        if (d1[v] + 1 < d1[u]) {
            d1[u] = d1[v] + 1;
            q.push_back(u);
        }
    }
}
    
    
    
for(int i=1;i<=n;i++) d2[i] = INF;  
    
s = n;   
    
d2[s] = 0;
q.push_front(s);
while (!q.empty()) {
    int v = q.front();
    q.pop_front();
    for (auto edge : g[v]) {
        int u = edge;
        if (d2[v] + 1 < d2[u]) {
            d2[u] = d2[v] + 1;
            q.push_back(u);
        }
    }
}
    
    
}

void solve()
{
   int m,k;
   
   cin >> n >> m >> k;
    
   int s[k];
   
   f(i,k) cin >> s[i];
    
   int u,v;
    
   f(i,m)
   {
       cin >> u >> v;
       g[u].pb(v);
       g[v].pb(u);
   }
    
   go();
    
   int res = d1[n];
    
   vector<pii> p,q;
    
    f(i,k) p.pb({d1[s[i]],s[i]});
    f(i,k) q.pb({d2[s[i]],s[i]}); 
    
    sort(p.begin(),p.end());
    sort(q.begin(),q.end());
    
    multiset<int> st;
    f(i,k) st.insert(d2[s[i]]);
    
    int mx = 0;
    
    for(int i=0;i<k;i++)
    {
        st.erase(st.find(d2[p[i].S]));
        if(st.size() > 0) mx = max(mx,p[i].F + (*st.rbegin()));
    }
    
    f(i,k) st.insert(d1[s[i]]);
    
    for(int i=0;i<k;i++)
    {
        st.erase(st.find(d1[q[i].S]));
       if(st.size() > 0) mx = max(mx,q[i].F + (*st.rbegin()));
    }
    
    res = min(res,mx+1);
    
    cout << res;
}

signed main()
{
    fast;
    solve();
}