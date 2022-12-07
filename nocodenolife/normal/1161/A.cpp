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
#define mem(x) memset(x,-1,sizeof(x))
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

    int n,k;
    cin>>n>>k;
    int arr[k];
    int first[n];
    int last[n];
    
    mem(first);
    mem(last);
    
    ForA1(k)
    {
        cin>>arr[i];
        if(first[arr[i]-1]==-1)
            first[arr[i]-1] = i;
        last[arr[i]-1] = i;
    }
    
    int ans = 0;
    int f,l;
    for(int i=0;i<=n-1;i++)
    {
        
        if(first[i]==-1)
        {
            ans++;
        }
        
        f = i;
        l = i+1;
        if(l>=0 && l<n)
        {
            if(first[l]==-1)
                ans++;
            else if(first[f]==-1)
                ans++;
            else
            {
                if(first[f]>last[l])
                    ans++;
            }
        }
        
        f = i;
        l = i-1;
        if(l>=0 && l<n)
        {
            if(first[l]==-1)
                ans++;
            else if(first[f]==-1)
                ans++;
            else
            {
                if(first[f]>last[l])
                    ans++;
            }
        }
    }
    cout<<ans<<endl;
    
    return 0;
}