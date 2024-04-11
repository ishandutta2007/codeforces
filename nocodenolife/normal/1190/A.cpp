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
    ll n,m,k;
    cin>>n>>m>>k;
    ll arr[m];
    ForA1(m)
    {
    	cin>>arr[i];
    	arr[i]--;
    }

    ll itr = 0;
   	ll start,end;
   	ll page,rem;
   	ll count;
   	ll ans = 0;
   	while(itr!=m)
   	{
   		rem = itr;
   		page = (arr[itr]-rem)/k;
   		start = page*k+rem;
   		end = start+k-1;
   		count = 0;
   		while(itr<m && arr[itr]<=end)
   		{
   			count++;
   			itr++;
   		}
   		if(count>0)
   		{
   			ans++;
   		}
   	}
   	cout<<ans<<endl;
    return 0;
}