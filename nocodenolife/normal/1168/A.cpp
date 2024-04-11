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

    int arr[n];
    ForA1(n)
    	cin>>arr[i];

    int low = 0;
    int high = m-1;
    int mid,maxi,val;
    bool possible = true;
    while(low<high)
    {
    	mid = (low+high)/2;
    	//cout<<mid<<endl;
    	possible = true;
    	maxi =0;
    	for(int i=0;i<n;i++)
    	{
    		val = arr[i]+mid;
    		if(val>=m)
    		{
    			val-=m;
    			if(val>=maxi)
    				continue;
    			else
    			{
    				if(arr[i]>maxi)
    					maxi = arr[i];
    			}
    		}
    		else
    		{
    			if(val>=maxi)
    			{
    				if(arr[i]>maxi)
    					maxi = arr[i];
    				continue;
    			}
    			possible = false;
    			break;
    		}
    	}
    	if(possible)
    		high = mid;
    	else
    		low = mid+1;
    }
    cout<<low<<endl;
    return 0;
}