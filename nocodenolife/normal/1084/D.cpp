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

#define modder 1000000007
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define F first
#define S second
#define mem(x) memset(x,0,sizeof(x))
#define PI 3.1415926535897932384626433832795l
#define deci(n) cout<<fixed<<setprecision(n);


using namespace std;

ll arr[300001];
ll order[300001];
ll parent[300001];
ll temp;

class Graph 
{ 
public: 
    ll V;     
    list<ll> * adj; 
  
    // A function used by topologicalSort 
    void topologicalSortUtil(ll v, bool visited[], queue<ll> &Stack); 

    Graph(ll V);    
    void addEdge(ll v, ll u); 
    void topologicalSort(); 
}; 
  
Graph::Graph(ll V) 
{ 
    this->V = V; 
    adj = new list<ll>[V]; 
} 
  
void Graph::addEdge(ll v, ll u) 
{ 
    adj[v].push_back(u);
    adj[u].push_back(v); // Add w to vs list. 
} 
  
// A recursive function used by topologicalSort 
void Graph::topologicalSortUtil(ll v, bool visited[],  
                                queue<ll> &Stack) 
{ 
    // Mark the current node as visited. 
    visited[v] = true; 
  
    // Recur for all the vertices adjacent to this vertex 
    list<ll>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
    {
        if (!visited[(*i)]) 
        {
            topologicalSortUtil((*i), visited, Stack); 
            parent[(*i)] = v;
        }
    }
  
    // Push current vertex to stack which stores result 
    Stack.push(v); 
} 
  
// // The function to do Topological Sort. It uses recursive  
// // topologicalSortUtil() 
void Graph::topologicalSort() 
{ 
    queue<ll> Stack; 
    
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    for (ll i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Call the recursive helper function to store Topological 
    // Sort starting from all vertices one by one 
    for (ll i = 0; i < V; i++) 
    {
      if (visited[i] == false) 
      {
        parent[i]=-1;
        topologicalSortUtil(i, visited, Stack); 
        }
    }
  
    // Print contents of stack 
    temp = 0;
    while (Stack.empty() == false) 
    { 
        order[temp] = Stack.front();
        temp++; 
        Stack.pop(); 
    } 
} 


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;

    ll answer =0;
    ForA1(n)
    {
        cin>>arr[i];
        if(arr[i]>answer)
            answer= arr[i];
    }
    map<pair<ll, ll>, ll> vis; 
    Graph g(n);
    ll u,v,wt;
    ForA1(n-1)
    {
        cin>>u>>v>>wt;
        u--;
        v--;
        g.addEdge(u,v);
        vis[{u,v}] = wt;
        vis[{v,u}] = wt;
    }
    g.topologicalSort();

    vector<ll> used[n];

    for(ll i=0;i<n;i++)
    {
        v = order[i];
        // cout<<v<<" ";
        if(used[v].size()==0)
        {
            if(parent[v]!=-1)
                used[parent[v]].push_back(arr[v] - vis[{parent[v],v}]);
        }
        else if(used[v].size()==1)
        {
            wt = used[v][0];
            if(wt<0)
                wt = 0;
            if(wt+arr[v]>answer)
                answer = wt+arr[v];
            if(parent[v]!=-1)
                used[parent[v]].push_back(arr[v]+wt - vis[{parent[v],v}]);
        }
        else
        {
            ll max1=-1,max2=-1;
            ll siz = used[v].size();
            for(ll j=0;j<siz;j++)
            {
                if(used[v][j]>=max1)
                {
                    max2 = max1;
                    max1 = used[v][j];
                    continue;
                }
                if(used[v][j]>max2)
                {
                    max2 = used[v][j];
                    continue;
                }
            }
            if(max1<0)
                max1=0;
            if(max2<0)
                max2=0;

            if(max1+max2+arr[v]>answer)
                answer=max1+max2+arr[v];
            if(parent[v]!=-1)
                used[parent[v]].push_back(arr[v]+max1 - vis[{parent[v],v}]);
        }
    }

    // cout<<endl;
    cout<<answer<<endl;

    return 0;
}