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

#include<iostream> 
#include <list> 
#include <limits.h> 
  
using namespace std; 

vector<pair<ll,ll>> edges[100005];
int visited[100005];
vector<pair<ll,pair<ll,ll>>> init;
ll finish[100005];
ll tim,flag;

void dfs(ll start, ll cost)
{   
    visited[start]=1;
    for(auto v: edges[start])
    {
        if(v.second<=cost || visited[v.first]==2)
            continue;
        if(visited[v.first]==1)
        {
            flag = 1;
            continue;
        }
        dfs(v.first,cost);
    }

    visited[start] = 2;
    finish[start] = tim++;
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

    ll n,m,u,v,c;
    cin>>n>>m;

    ForA1(m)
    {
        cin>>u>>v>>c;
        u--;v--;
        edges[u].push_back(make_pair(v,c));
        init.push_back(make_pair(c,make_pair(u,v)));
    }

    mem(visited);
    ll cost = 0,mid_cost;
    ll max_cost  = mod;

    while(cost<max_cost)
    {
        mid_cost = (max_cost+cost)/2;
        flag = 0;
        tim=0;

        mem(visited);
        ForA1(n)
        {
            if(visited[i]==0)
                dfs(i,mid_cost);
        }

        if(flag==0)
        {
            max_cost = mid_cost;        }
        else
        {
            cost = mid_cost+1;
        }
    }   
    cout<<cost<<" ";

    flag =0;
    tim=0;
    mem(visited);
    ForA1(n)
    {
        if(visited[i]==0)
            dfs(i,cost);
    }

    vector<ll> ans;

    ForA1(m)
    {
        c = init[i].first;
        u = (init[i].second).first;
        v = (init[i].second).second;
        if(c<=cost)
        {
            if(finish[u]<finish[v])
            {
                ans.pb(i);
            }
        }
    }

    cout<<ans.size()<<endl;
    for(auto i: ans)
        cout<<i+1<<" ";

    cout<<endl;
    

    return 0;
}