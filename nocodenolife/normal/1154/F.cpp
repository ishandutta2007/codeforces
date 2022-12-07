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

    int n,m,k;
    cin>>n>>m>>k;
    int arr[n];
    
    ForA1(n)
        cin>>arr[i];
    sort(arr,arr+n);
    
    int offers[k+1]={0};
    int sums[k+2];
    sums[0] = 0;
    sums[1] = arr[0];
    for(int i=2;i<=k;i++)
    {
        sums[i] = arr[i-1]+sums[i-1];
        //cout<<sums[i]<<endl;
    }
    
    
    int a,b;
    ForA1(m)
    {
        cin>>a>>b;
        if(a>k)
            continue;
        offers[a] = max(offers[a],b);
    }
    
    int vals[k+2] = {0};
    int nums=0;
    int amoun;
    for(int i=k;i>=1;i--)
    {
        vals[i] = INT_MAX;
        nums++;
        for(int j=1;j<=nums;j++)
        {
            b = offers[j];
            amoun = sums[i+j-1] - sums[i+b-1];
            amoun += vals[i+j];
            if(vals[i]>amoun)
                vals[i]=amoun;
        }
        //cout<<vals[i]<<endl;
    }
    cout<<vals[1]<<endl;
    return 0;
}