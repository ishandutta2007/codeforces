#include <bits/stdc++.h>

typedef unsigned long long int ull;
typedef long double ldb;
typedef long long int ll;

#define ForA1(n)  for (ll i=0; i<n; i++)
#define ForA2(n)  for (ll j=0; j<n; j++)
#define ForA3(n)  for (ll k=0; k<n; k++)
#define ForN1(n)  for (ll i=1; i<=n; i++)
#define ForN2(n)  for (ll j=1; j<=n; j++)
#define ForN3(n)  for (ll g=1; g<=n; g++)

#define mod 998244353 
#define pb push_back
#define mp make_pair
#define vll vector<ll>
#define F first
#define S second
#define debug(x)    cerr << #x << " = " << x << endl;
#define mem(x) memset(x,false,sizeof(x))
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
    
    ll n,x;
    cin>>n;
    ll count2 = 0, count1=0;
    
    ForA1(n)
    {
        cin>>x;
        if(x==1)
            count1++;
        else
            count2++;
    }
    
    if(count2>0)
    {
        cout<<"2 ";
        count2--;
    }
    if(count1>0)
    {
        cout<<"1 ";
        count1--;
    }
    ForA1(count2)
    {
        cout<<"2 ";
    }
    ForA1(count1)
    {
        cout<<"1 ";
    }
    cout<<endl;
    return 0;
}