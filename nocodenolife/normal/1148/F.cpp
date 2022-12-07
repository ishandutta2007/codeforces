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

bool isReversed(ll a, ll b)
{
    a = a&b;
    b=0;
    ll curr = 1;
    ForA1(62)
    {
        if(a&curr)
            b++;
        curr*=2;
    }
    if(b%2==0)
        return false;
    return true;
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

    ll n;
    ll sum=0;
    cin>>n;
    ll arr[n];
    ll mask[n];
    ForA1(n)
    {
        cin>>arr[i];
        cin>>mask[i];
        sum+=arr[i];
    }
    if(sum>0)
    {
        ForA1(n)
            arr[i]*=-1;
    }
    
    ll ans =0;
    ll curr = 1;
    for(ll val=0;val<62;val++)
    {
        sum =0;
        //cout<<curr<<endl;
        ForA1(n)
        {
            if(val!=61 && mask[i]>2*curr)
                continue;
            if((mask[i]&curr)!=0)
            {
                if(isReversed(ans,mask[i]))
                    sum-=arr[i];
                else
                    sum+=arr[i];
                //cout<<(mask[i]&curr);
            }
        }
        //cout<<endl;
        
        if(sum<0)
            ans+=curr;
        curr*=2;
    }
    cout<<ans<<endl;
    
    return 0;
}