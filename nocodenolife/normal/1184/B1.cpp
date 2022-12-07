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
 	
 	ll s,b;
 	cin>>s>>b;

 	ll a[s];
 	pair<ll,ll> base[b];

 	ForA1(s)
 	{
 		cin>>a[i];
 	}

 	ll d,g;
 	ForA1(b)
 	{
 		cin>>d>>g;
 		base[i] = {d,g};
 	}

 	sort(base,base+b);

 	for(ll i=1;i<b;i++)
 	{
 		base[i].second += base[i-1].second;
 	}

 	ll mini,maxi,mid;

 	ForA1(s)
 	{
 		d = a[i];
 		if(d<base[0].first)
 		{
 			cout<<"0 ";
 			continue;
 		}
 		mini = 0;
 		maxi = b;

 		while(maxi-mini>1)
 		{
 			mid  = mini + maxi;
 			mid/=2;
 			if(base[mid].first > d)
 			{
 				maxi = mid;
 			}
 			else
 			{
 				mini = mid;
 			}
 		}

 		cout<<base[mini].second<<" ";
 	}

    return 0;
}