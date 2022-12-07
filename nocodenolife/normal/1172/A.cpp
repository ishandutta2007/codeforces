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
    cin>>n;
    ll hand[n+1];
    ll stack[n+1];
    
    ForN1(n)
        cin>>hand[i];
    ForN1(n)
        cin>>stack[i];
    
    ll max_ans = 0;
    ForN1(n)
    {
        if(stack[i]==0)
            continue;
        max_ans = max(max_ans, i-stack[i]+1);
    }
    max_ans+=n;
    
    //Check if diretly start pushing
    ll end = stack[n];
    ll maxi = 0;
    bool isPos = true;
    ll c=1;
    for(ll i = n-end+1;i<=n;i++)
    {
        if(stack[i]!=c)
        {
            isPos = false;
            break;
        }
        c++;
    }
    ForN1(n-end)
    {
        if(stack[i]==0)
            continue;
        maxi = max(maxi, i-stack[i]+end+1);
    }
    if(maxi!=0)
        isPos = false;
    
    if(isPos)
    {
        cout<<n-end<<endl;
    }
    else
    {
        cout<<max_ans<<endl;
    }
    return 0;
}