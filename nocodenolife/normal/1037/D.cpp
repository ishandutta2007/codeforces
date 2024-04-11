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

void addEdge(vector<ll> adj[], ll u, ll v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;

    vector<ll> adj[n];

    for(ll i=1;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        x--;
        y--;
        addEdge(adj,x,y);
    }

    ll arr[n];
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
        arr[i]--;
    }

    if(arr[0]!=0)
    {
        cout<<"No"<<endl;
        return 0;
    }

    ll visited[n] = {0};
    queue <ll> check;
    check.push(arr[0]);
    visited[arr[0]] = 1;
    ll counter = 1;
    ll temp[n] = {0};

    while(check.size()!=0 && counter!=n)
    {
        ll par = check.front();
        check.pop();
        ll size = 0;
        
        for(ll i=0;i<adj[par].size();i++)
        {
            if(visited[adj[par][i]]==0)
            {
                visited[adj[par][i]]=1;
                temp[adj[par][i]]=1;
                size++;
            }
        }

        while(size>0)
        {
            if(temp[arr[counter]]!=1)
            {
                cout<<"No"<<endl;
                return 0;
            }
            temp[arr[counter]]=0;
            check.push(arr[counter]);
            counter++;
            size--;
        }

    }

    if(counter!=n)
    {
        cout<<"No"<<endl;
        return 0;
    }

    cout<<"Yes"<<endl;

    
    return 0;
}