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

ll arr[150];
//int V;
//int INF;
vector<ll> adj[150];
//int dp[130][130];
ll v[150];
ll parent[150];

ll isConnected(ll x, ll y)
{
	while(x!=0 || y!=0)
	{
		if(x%2==1 && y%2==1)
			return 1;
		x/=2;
		y/=2;
	}
	return 0;
}


ll bfs(ll u) 
{ 
    queue<ll> q; 
  	memset(v,-1,sizeof(v));
  	memset(parent,-1,sizeof(parent));

    q.push(u); 
    v[u] = 0; 
  	ll f;
  	ll x;
  	ll ans = INT_MAX;
    while (!q.empty()) { 
  
        f = q.front(); 
        q.pop(); 
  
        for (auto i = adj[f].begin(); i != adj[f].end(); i++) { 
            if (v[*i]==-1) { 
                q.push(*i); 
                v[*i] = v[f]+1;
                parent[*i] = f;
            } 
            else if(parent[*i]!=f && parent[f]!=*i)
            {
            	x = v[f] + v[*i] +1;
            	if(x>2)
            		ans = min(ans,x);
            }
        } 
    } 

    return ans;
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

    ll num;
    cin>>num;
    
    ll n = 0;
    ll temp;

    ForA1(num)
    {
    	cin>>temp;
    	if(temp!=0)
    	{
    		arr[n] = temp;
    		n++;
    	}
    	if(n==130)
    		break;
    }

    if(n==130)
    {
    	cout<<3<<endl;
    	return 0;
    }

    for(ll i=0;i<n;i++)
    {
    	for(ll j=i+1;j<n;j++)
    	{
    		temp = isConnected(arr[i],arr[j]);
    		if(temp>0)
    		{
    			//cout<<i<<" "<<j<<endl;
    			adj[i].push_back(j);
    			adj[j].push_back(i);
    		}
    	}	
    }

    ll ans = INT_MAX;
    ll x;
    ForA1(n)
    {
    	x = bfs(i);
    	ans = min(ans,x);
    }

    if(ans==INT_MAX)
    	ans=-1;

    cout<<ans;

    return 0;
}