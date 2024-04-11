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

int findAns(ll n, ll k, string s,char c)
{
	if(n<=k)
		return 1;
	ll count=0;
    for(ll i=0;i<n;i++)
    {
    	if(s[i]==c)
    		count++;
    }

    ll loc=0;
    for(ll i=0;i<k-1;i++)
    {
    	if(s[i]==c)
    		loc++;
    }

    for(ll i=k-1;i<n;i++)
    {
    	if(s[i]==c)
    		loc++;
    	if(loc==count)
    	{
    		return 1;
    		//player to move wins
    	}
    	if(s[i-k+1]==c)
    		loc--;
    }
    return 0;
}

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
    string s;
    cin>>s;

    
    if(findAns(n,k,s,'0')==1 || findAns(n,k,s,'1')==1)
    {
    	cout<<"tokitsukaze"<<endl;
    	return 0;
    }

    
    string x = "";
    for(int i=k;i<n;i++)
    {
    	x.push_back(s[i]);
    }
    if(findAns(n-k,k,x,'0')==0 || findAns(n-k,k,x,'1')==0)
    {
    	cout<<"once again"<<endl;
    	return 0;
    }

    x = "";
    for(int i=0;i<n-k;i++)
    {
    	x.push_back(s[i]);
    }
    if(findAns(n-k,k,x,'0')==0 || findAns(n-k,k,x,'1')==0)
    {
    	cout<<"once again"<<endl;
    	return 0;
    }

    char l = s[0];
    char r='0';
    if(l=='0')
    	r='1';

    for(int i=k+1;i<n;i++)
    {
    	if(s[i]!=r)
    	{
    		cout<<"once again"<<endl;
    		return 0;
    	}
    }

    for(int i=k+2;i<n;i++)
    {
    	if(s[i-k-1]!=l)
    	{
    		cout<<"once again"<<endl;
    		return 0;
    	}
    }
    cout<<"quailty"<<endl;

    return 0;
}