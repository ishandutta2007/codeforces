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

    char arr[n][m];
    ForA1(n)
    {
    	ForA2(m)
    		cin>>arr[i][j];
    }
    int up[n][m];
    int down[n][m];
    int right[n][m];

    mem(up);
    mem(down);
    mem(right);

    for(ll i=1;i<n;i++)
    {
    	for(ll j=0;j<m;j++)
    	{
    		if(arr[i][j]==arr[i-1][j])
    		{
    			up[i][j] = 1+up[i-1][j];
    		}
    	}
    }

    for(ll i=n-2;i>=0;i--)
    {
    	for(ll j=0;j<m;j++)
    	{
    		if(arr[i][j]==arr[i+1][j])
    		{
    			down[i][j] = 1+down[i+1][j];
    		}
    	}
    }

    for(ll i=0;i<n;i++)
    {
    	for(ll j=m-2;j>=0;j--)
    	{
    		if(arr[i][j]==arr[i][j+1])
    		{
    			right[i][j] = 1+right[i][j+1];
    		}
    	}
    }

    /*ForA1(n)
    {
    	ForA2(m)
    	{
    		cout<<up[i][j]<<" ";
    	}
    	cout<<endl;
    }*/

    ll ans = 0;
    ll hi;
    ll next,prev;
    int width;
    for(ll j=0;j<m;j++)
    {
    	for(ll i=1;i<n-1;i++)
    	{
    		if(arr[i][j]==arr[i-1][j])
    			continue;

    		hi = down[i][j];
    		next = i+hi+1;
    		if(next>=n)
    			break;

    		if(up[i-1][j]<hi)
    			continue;

    		if(down[next][j]<hi)
    			continue;

    		width = 100000;

    		prev = i-hi-1;
    		next = next+hi;

    		for(ll k=prev;k<=next;k++)
    		{
    			width = min(width,right[k][j]);
    		}

    		ans+= (ll)(width+1);
    	}
    }

    cout<<ans<<endl;

    return 0;
}