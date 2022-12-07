#include <bits/stdc++.h>

typedef unsigned long long int ull;
typedef long double ldb;
typedef long long int ll;

#define ForA1(n)  for (ll i=0; i<n; i++)
#define ForA2(n)  for (ll j=0; j<n; j++)
#define ForA3(n)  for (ll k=0; k<n; k++)
#define ForN1(n)  for (ll i=1; i<=n; i++)
#define ForN2(n)  for (ll j=1; j<=n; j++)
#define ForN3(n)  for (ll k=1; k<=n; k++)

#define mod 998244353 
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pair pair<int,int>
#define F first
#define S second
#define mem(x) memset(x,0,sizeof(x))
#define PI 3.1415926535897932384626433832795l
#define deci(n) cout<<fixed<<setprecision(n);


using namespace std;

ll mypower(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
       if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

class Graph 
{ 
    ll V;    // No. of vertices 
  
    // Pointer to an array containing adjacency 
    // lists 
    list<ll> *adj;    
public: 
    Graph(ll V);  // Constructor 
  
    // function to add an edge to graph 
    void addEdge(ll v, ll w);  
  
    // prints BFS traversal from a given source s 
    ll solve();   
}; 
  
Graph::Graph(ll V) 
{ 
    this->V = V; 
    adj = new list<ll>[V]; 
} 
  
void Graph::addEdge(ll v, ll w) 
{ 
    adj[v].push_back(w); // Add w to vs list. 
    adj[w].push_back(v);
} 
  
ll Graph::solve() 
{ 
    ll ans = 1;
    ll answer =0;
    ll even =0;
    ll odd =0;
    ll s;
    ll *visited = new ll[V]; 
    for(ll i = 0; i < V; i++) 
    {
        visited[i] = -1; 
    }
    
    for(ll b=0;b<V;b++)
    {
        even = 0;
        odd =0;
        if(visited[b]!=-1)
            continue;
        list<ll> queue; 
        
        visited[b] = 0; 
        even++;
        queue.push_back(b); 
    
        list<ll>::iterator i; 
    
        while(!queue.empty()) 
        { 
            s = queue.front(); 
            //cout << s << " "; 
            queue.pop_front(); 
    
            for (i = adj[s].begin(); i != adj[s].end(); ++i) 
            { 
                if (visited[*i]==-1) 
                { 
                    visited[*i] = visited[s]+1;
                    if(visited[*i]%2==0)
                        even++;
                    else
                        odd++; 
                    queue.push_back(*i); 
                } 
                else{
                    if((visited[s]+visited[*i])%2==0)
                    {
                        answer = -1;
                        return 0;
                    }
                }
            } 
        } 
        answer =0;
        answer+= mypower(2,even,mod);
        answer+=mypower(2,odd,mod);
        answer%=mod;

        ans*=answer;
        ans%=mod;
    }
    
    return ans;
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    ll n,m,u,v;

    ForA3(t)
    {
        cin>>n>>m;
        Graph g(n);

        for(ll i=0;i<m;i++)
        {
            cin>>u>>v;
            u--;
            v--;
            g.addEdge(u,v);
        }

        cout<<g.solve()<<endl;
    }

    return 0;
}