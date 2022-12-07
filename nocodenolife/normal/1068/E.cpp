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

vector<ll> adj[100001];
ll degree[100001];
void addEdge(ll u, ll v) 
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
} 

int checker(ll size, ll k)
{
    if(k==1)
    {
        ll counter=0;
        for(ll i=0;i<size;i++)
        {
            degree[i] = adj[i].size();
            if(degree[i]==2)
                return -1;
            if(degree[i]>1)
                counter++;
        }
        if(counter!=1)
            return -1;
        return 0;
    }
    ll flag=0;
    for(ll i=0;i<size;i++)
    {
        degree[i] = adj[i].size();
        if(degree[i]==2)
            return -1;
    }
    for(ll i=0;i<size;i++)
    {
        flag = 0;
        if(degree[i]==0)
        {
            continue;
        }
        if(degree[i]==1)
        {
            adj[i].clear();
            continue;
        }
        for(ll j=0;j<adj[i].size();j++)
        {
            if(degree[adj[i][j]]==1)
            {
                flag = 1;
                break;
            }
        }
        if(flag==0)
            continue;
        flag = 0;
        ll deg;
        for(ll j=0;j<adj[i].size();j++)
        {
            if(degree[adj[i][j]]!=1)
            {
                flag ++;
                deg = j;
            }
        }
        
        if(flag!=1)
            return -1;
        adj[i].clear();
        adj[i].pb(deg);
        if(degree[i]<=3)
            return -1;
    }    
    return checker(size, k-1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  

    ll n,k;
    cin>>n>>k;

    ll start,end;
    ForA1(n-1)
    {
        cin>>start>>end;
        start--;end--;
        addEdge(start,end);
    }

    if(k>=12 || n<4)
    {
        cout<<"No"<<endl;
        return 0;
    }

    ll ans = checker(n,k);

    if(ans!=0)
    {
        cout<<"No"<<endl;
    }
    else
    {
        cout<<"Yes"<<endl;
    }


    return 0;
}