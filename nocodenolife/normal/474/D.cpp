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

#define modder 1000000007
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define F first
#define S second
#define mem(x) memset(x,-1,sizeof(x))
#define PI 3.1415926535897932384626433832795l
#define deci(n) cout<<fixed<<setprecision(n);

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t,k;
    cin>>t>>k;
    ll temp;
    ll dp[100005];
    dp[0]=1;
    ForN1(100004)
    {
        temp = dp[i-1];
        if(i-k>=0)
            temp+=dp[i-k];
        dp[i] = temp%modder;
    }
    
    ForN1(100003)
    {
        dp[i+1] += dp[i];
        dp[i+1]%=modder;
    }
        
    ll a,b;
    ForA3(t)
    {
        cin>>a>>b;
        a--;
        temp = dp[b];
        if(a>0)
            temp-=dp[a];
        temp+=modder;
        temp%=modder;
        cout<<temp<<endl;
    }
    
    return 0;
}