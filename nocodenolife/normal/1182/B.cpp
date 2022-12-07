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

    ll h,w;
    cin>>w>>h;

    char arr[w][h];
    bool ans= true;

    ForA1(w)
    {
        ForA2(h)
        {
    	    cin>>arr[i][j];
    	    //cout<<arr[i][j];
        }
    }

    ll idxi=-1,idxj = -1;

    for(ll i=1;i<w-1;i++)
    {
    	for(ll j=1;j<h-1;j++)
    	{
    		if(arr[i][j]=='*' && arr[i-1][j]=='*'&&arr[i+1][j]=='*' && arr[i][j-1]=='*' && arr[i][j+1]=='*')
    		{
    			idxi =i;
    			idxj = j;
    		}
    	}
    }
    //debug(idxi);
    //debug(idxj);
    //cout<<idxi<<idxj;
    if(idxj==-1)
    {
    	cout<<"NO"<<endl;
    	return 0;
    }
    ll idx = idxj-1;
    while(idx>=0 && arr[idxi][idx]=='*')
    {
    	arr[idxi][idx]='.';
    	idx--;
    }
    idx = idxj+1;
    while(idx<h && arr[idxi][idx]=='*')
    {
    	arr[idxi][idx]='.';
    	idx++;
    }

    idx = idxi-1;
    while(idx>=0 && arr[idx][idxj]=='*')
    {
    	arr[idx][idxj]='.';
    	idx--;
    }
    idx = idxi+1;
    while(idx<w && arr[idx][idxj]=='*')
    {
    	arr[idx][idxj]='.';
    	idx++;
    }
    arr[idxi][idxj]='.';

    ForA1(w)
    {
    	ForA2(h)
    	{
    		//cout<<arr[i][j];
    		if(arr[i][j]=='*')
    		{
    			//debug(i);
    			//debug(j);
    			ans = false;
    			//break; 
    		}
    	}
    }
    if(ans==true)
    {
    	cout<<"YES"<<endl;
    }
    else
    {
    	cout<<"NO"<<endl;
    }
    return 0;
}