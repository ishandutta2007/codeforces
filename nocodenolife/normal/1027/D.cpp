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

#define mod 1000000007
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

vector<int> tempo;
ll answer =0;
int arr[200005];
int cost[200005];
class Graph
{
    int V; 
 
    list<int> *adj;
 
    void DFSUtil(int v, bool visited[]);
public:
    Graph(int V); 
    void addEdge(int v, int w);
    void connectedComponents();
};
 
void Graph::connectedComponents()
{
    bool *visited = new bool[V];
    for(int v = 0; v < V; v++)
        visited[v] = false;
 
    for (int v=0; v<V; v++)
    {
        if (visited[v] == false)
        {
            tempo.clear();
            DFSUtil(v, visited);
            int start = -1;
            int fir = tempo[0];
            map<int,int>mapper;
            mapper[fir]++;
            while(1)
            {
                fir = arr[fir];
                mapper[fir]++;
                if(mapper[fir]==2)
                {
                    start = fir;
                    break;
                }
            }
            ll mn = cost[fir];
            fir = arr[fir];
            while(fir!=start)
            {
                if(cost[fir]<mn)
                    mn = cost[fir];
                fir = arr[fir];
            }
            answer+=mn;
        }
    }
}
 
void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    tempo.push_back(v);

    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            DFSUtil(*i, visited);
}
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    ForA1(n)
    {
        cin>>cost[i];
    }
    Graph g(n);

    ll min=0;
    ForA1(n)
    {
        int next;
        cin>>next;
        next--;
        arr[i] = next;
        if(next==i)
        {
            min+= cost[i];
        }
        else
        {
            g.addEdge(i,next);
        }
    }
    g.connectedComponents();
    //answer+=min;
    cout<<answer<<endl;
    return 0;
}