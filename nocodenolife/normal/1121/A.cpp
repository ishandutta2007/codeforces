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

    int n,m,k;
    cin>>n>>m>>k;

    int power[n];
    int school[n];

    ForA1(n)
    {
    	cin>>power[i];
    }

    ForA1(n)
    {
    	cin>>school[i];
    }
    int answer = 0;

    int id,sc,pow;
    ForA1(k)
    {
    	cin>>id;
    	id--;

    	sc = school[id];
    	pow = power[id];

    	ForA2(n)
    	{
    		if(school[j]==sc && power[j]>pow)
    		{
    			answer++;
    			break;
    		}
    	}
    }
    cout<<answer<<endl;
    return 0;
}