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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;

    ll b[n];
    ll a[n];

    for(ll i=0;i<n;i++)
    {
        cin>>b[i];
    }

    ll start = -1;
    ll max = -1;

    for(ll i=0;i<n;i++)
    {
    	if(b[i]!= b[(i+1)%n])
    	{
    		if(b[(i+1)%n]>max)
        	{
            	start = (i+1)%n;
           	 	max = b[(i+1)%n];
        	}
    	}
    }
	if(start==-1)
	{
		for(int i=0;i<n;i++)
		{
			if(b[i]!=0)
			{
				cout<<"NO"<<endl;
				return 0;
			}
		}
		cout<<"YES"<<endl;
        for(ll i=0;i<n;i++)
        {
            cout<<"1 ";
        }
        cout<<endl;
        return 0;		
	}
    a[start] = b[start];
    ll prev = start;
    ll counter = (start-1);
    if(counter<0)
    {
        counter+=n;
    }

    a[counter] = 2*a[start] + b[counter];
    prev = counter;
    counter--;
    if(counter<0)
    {
        counter+=n;
    }
    while(counter!=start)
    {
        a[counter] = a[prev] + b[counter];
        prev = counter;
        counter--;
        if(counter<0)
        {
            counter+=n;
        }
    }

    for(ll i=0;i<n;i++)
    {
        if(b[i] != a[i] % a[(i+1)%n])
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    for(ll i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    return 0;
}