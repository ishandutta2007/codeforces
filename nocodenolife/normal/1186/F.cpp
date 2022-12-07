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
#define mem(x) memset(x,0,sizeof(x))
#define PI 3.1415926535897932384626433832795l
#define deci(n) cout<<fixed<<setprecision(n);


using namespace std;

int v;
int e;
vector<int> adj[1000005];
int degree[1000005];
int tored[1000005];

std::map<pair<int,int>, int> mapper;


void RemoveEdge(int u)
{
	int mini,maxi;
	for(int i=0;i<adj[u].size();i++)
	{
		mini = min(u,adj[u][i]);
		maxi = max(u,adj[u][i]);

		if(mapper[{mini,maxi}]==1)
			continue;

		if(tored[mini]>0 && tored[maxi]>0)
		{
			tored[mini]--;
			tored[maxi]--;
			e--;
			mapper[{mini,maxi}]=1;
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

    cin>>v;
    cin>>e;

    ForN1(v)
    {
    	degree[i]=0;
    }
    ll a,b;
    ForN1(e)
    {
    	cin>>a>>b;
    	degree[a]++;
    	degree[b]++;
    	adj[a].push_back(b);
    	adj[b].push_back(a);
    }

    vector<pair<int,int>> order;
    ForN1(v)
    {
    	tored[i] = degree[i]/2;
    	order.push_back({tored[i],i});
    }

    sort(order.begin(),order.end());

    for(int i=v-1;i>=0;i--)
    {
    	RemoveEdge(order[i].second);
    }

    cout<<e<<"\n";
    int mini,maxi;
    for(int u =1; u<=v;u++)
    {
		for(int i=0;i<adj[u].size();i++)
		{
			mini = min(u,adj[u][i]);
			maxi = max(u,adj[u][i]);

			if(mapper[{mini,maxi}]==1)
				continue;

			cout<<mini<<" "<<maxi<<"\n";
			mapper[{mini,maxi}]=1;
		}
    }

    return 0;
}