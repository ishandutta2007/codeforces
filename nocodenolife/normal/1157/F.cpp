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

#define mod 998244353 
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

    int arr[200005];
    mem(arr);
    
    int n,x;
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        cin>>x;
        arr[x]++;
    }
    
    int ans =0;
    int start;
    int end;
    
    int val=0;
    int startval;
    
    for(int i=0;i<200005;i++)
    {
        if(arr[i]==0)
        {
            if(val>ans)
            {
                ans = val;
                start = startval;
                end = i-1;
            }
            val = 0;
            startval = i+1;
        }
        
        else if(arr[i]==1)
        {
            val++;
            if(val>ans)
            {
                ans = val;
                start = startval;
                end = i;
            }
            val = 1;
            startval = i;
        }
        
        else
        {
            val+=arr[i];
        }
    }
    
    cout<<ans<<endl;
    for(int i=start;i<=end;i++)
    {
        cout<<i<<" ";
    }
    
    for(int i=end;i>=start;i--)
    {
        val=arr[i]-1;
        for(int j=0;j<val;j++)
            cout<<i<<" ";
    }
    cout<<endl;
    
    return 0;
}