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

    int a[n][m];
    int b[n][m];

    ForA1(n)
    {
    	ForA2(m)
    	{
    		cin>>a[i][j];
    	}
    }

    ForA1(n)
    {
    	ForA2(m)
    	{
    		cin>>b[i][j];
    	}
    }
    vector<int> fora;
    vector<int> forb;
    for(int l=0;l<n+m-1;l++)
    {
    	fora.clear();
    	forb.clear();
    	for(int i=0;i<=l;i++)
    	{
    		if(i<0||i>=n)
    			continue;
    		if(l-i<0||l-i>=m)
    			continue;
    		fora.push_back(a[i][l-i]);

    		forb.push_back(b[i][l-i]);
    		// cout<<fora[i]<<forb[i]<<endl;
    	}
    	// cout<<endl;
    	sort(fora.begin(), fora.end());
    	sort(forb.begin(), forb.end());

    	ForA1(fora.size())
    	{
    		if(fora[i]!=forb[i])
    		{
    			cout<<"NO"<<endl;
    			return 0;
    		}
    	}
    }
    cout<<"YES"<<endl;

    return 0;
}