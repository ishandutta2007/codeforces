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

int main()
{
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin>>n>>m;

    int row[n];
    ForA1(n)
    	cin>>row[i];

    set <int, greater <int> > infront[n+1];

    int u,v;
    ForA1(m)
    {
    	cin>>u>>v;
    	infront[v].insert(u);
    }

    int currset[n+1] = {0};
    int las = row[n-1];

    set <int, greater <int> > :: iterator itr; 
    for (itr = infront[las].begin(); itr != infront[las].end(); ++itr) 
    { 
        currset[*itr]=1; 
    } 

    int ans = 0;
    int val;
    int checker=1;
    for(int i=n-2;i>=0;i--)
    {
    	val = row[i];
    	if(currset[val]==checker)
    		ans++;
    	else
    	{
    		checker++;
    		for (itr = infront[val].begin(); itr != infront[val].end(); ++itr) 
    		{ 
        		currset[*itr]++; 
    		}
    	}

    }

    cout<<ans<<endl;
    return 0;
}