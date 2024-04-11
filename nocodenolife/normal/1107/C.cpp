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

    ll n,k;
    cin>>n>>k;

    ll arr[n];
    ForA1(n)
    {
    	cin>>arr[i];
    }

    ll sum = 0;
    string s;
    cin>>s;

    vector<ll> consec;
    consec.push_back(arr[0]);
    for(ll i=1;i<n;i++)
    {

    	if(s[i]==s[i-1])
    	{
    		consec.push_back(arr[i]);
    	}
    	else
    	{
    		sort(consec.begin(), consec.end());
    		for(ll j=0; j<min((ll)(consec.size()), k); j++)
    		{
    			sum+= consec[consec.size() - 1 - j];
    		}

    		consec.clear();
    		consec.push_back(arr[i]);
    	}
    }
    sort(consec.begin(), consec.end());
    for(ll j=0; j<min((ll)(consec.size()), k); j++)
   	{
   		sum+= consec[consec.size() - 1 - j];
   	}

   	cout<<sum<<endl;

    return 0;
}