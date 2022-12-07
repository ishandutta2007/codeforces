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

    int n;
    cin>>n;

    vector<pair<int,int>> num;
    bool isInc[n];
    int countInc = 0,countDec=0,x=0;
    int arr[2*n+5];

    int a,b;

    ForA1(n)
    {
    	cin>>a>>b;

    	arr[a] = x;
    	arr[b] = x;
    	num.push_back({a,b});

    	if(b>a)
    	{
    		countInc++;
    		isInc[x] = true;
    		x++;
    	}
    	else
    	{
    		countDec++;
    		isInc[x] = false;
    		x++;
    	}
    }

    if(countInc>=countDec)
    {
    	cout<<countInc<<endl;
    	for(int i=2*n;i>0;i--)
    	{
    		x = arr[i];
    		if(isInc[x]==false)
    			continue;
    		cout<<x+1<<" ";
    		isInc[x] = false;
    	}
    }
    else
    {
    	cout<<countDec<<endl;
    	for(int i=1;i<=2*n;i++)
    	{
    		x = arr[i];
    		if(isInc[x]==true)
    			continue;
    		cout<<x+1<<" ";
    		isInc[x] = true;
    	}
    }
    cout<<endl;

    return 0;
}