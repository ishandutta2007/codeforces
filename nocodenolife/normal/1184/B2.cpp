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
#define vll vector<ll>
#define F first
#define S second
#define debug(x)    cerr << #x << " = " << x << endl;
#define mem(x) memset(x,false,sizeof(x))
#define PI 3.1415926535897932384626433832795l
#define deci(n) cout<<fixed<<setprecision(n);


using namespace std;
#define INF 99999 
#define M 1000
#define N 1000
#define V 100

int graph[100][100];
int dist[100][100];
bool canattack[M][N];

bool bpm(bool bpGraph[M][N], int u, 
         bool seen[], int matchR[]) 
{ 
    for (int v = 0; v < N; v++) 
    { 
        if (bpGraph[u][v] && !seen[v]) 
        { 
            seen[v] = true;  
  
            if (matchR[v] < 0 || bpm(bpGraph, matchR[v], 
                                     seen, matchR)) 
            { 
                matchR[v] = u; 
                return true; 
            } 
        } 
    } 
    return false; 
} 
int maxBPM(bool bpGraph[M][N]) 
{ 
    int matchR[N]; 
  
    memset(matchR, -1, sizeof(matchR)); 
    int result = 0;  
    for (int u = 0; u < M; u++) 
    { 
        bool seen[N]; 
        memset(seen, 0, sizeof(seen)); 
        if (bpm(bpGraph, u, seen, matchR)) 
            result++; 
    } 
    return result; 
} 


void floydWarshall ()  
{  
    int i, j, k;  
  
    for (i = 0; i < V; i++)  
        for (j = 0; j < V; j++)  
            dist[i][j] = graph[i][j];  
    for (k = 0; k < V; k++)  
    {  
        // Pick all vertices as source one by one  
        for (i = 0; i < V; i++)  
        {  
            // Pick all vertices as destination for the  
            // above picked source  
            for (j = 0; j < V; j++)  
            {  
                // If vertex k is on the shortest path from  
                // i to j, then update the value of dist[i][j]  
                if (dist[i][k] + dist[k][j] < dist[i][j])  
                    dist[i][j] = dist[i][k] + dist[k][j];  
            }  
        }  
    }  
} 

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,m;
    cin>>n>>m;

    ForA1(100)
    {
        ForA2(100)
        {
            graph[i][j] = INF;
        }
        graph[i][i]=0;
    }

    ll u,v;
    ForA1(m)
    {
        cin>>u>>v;
        u--;
        v--;
        if(u==v)
            continue;
        graph[u][v] = 1;
        graph[v][u]=1;
    }
    floydWarshall();

    ll s,b,k,h;
    cin>>s>>b>>k>>h;
    mem(canattack);

    ll loc[s];
    ll atack[s];
    ll fuel[s];

    ForA1(s)
    {
        cin>>loc[i]>>atack[i]>>fuel[i];
        loc[i]--;
    }

    ForA1(b)
    {
        cin>>u>>v;
        u--;

        ForA2(s)
        {
            if(dist[loc[j]][u] <=fuel[j]  && atack[j]>=v)
            {
                canattack[j][i] = true;
            }
        }
    }

    ll got = maxBPM(canattack);
    ll ans = got * k;
    ll left = s - got;
    ll sec = s*h;

    ans = min(ans,sec);
    cout<<ans<<endl;
    return 0;
}