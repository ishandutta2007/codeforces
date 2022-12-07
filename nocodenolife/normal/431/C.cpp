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
#define pair pair<int,int>
#define F first
#define S second
#define mem(x) memset(x,0,sizeof(x))
#define PI 3.1415926535897932384626433832795l
#define deci(n) cout<<fixed<<setprecision(n);

using namespace std;

ll dp[105];

ll solve(ll n, ll k)
{
    if(n<0)
        return 0;
    
    if(dp[n]!=-1)
        return dp[n];
    
    ll answer =0;
    for(ll i=k;i>0;i--)
    {
        answer+=solve(n-i,k);
        answer%=modder;
    }
    dp[n]=answer;
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,k,d;
    cin>>n>>k>>d;
    ll answer = 0;
    
    if(d>n)
    {
        cout<<"0"<<endl;
        return 0;
    }
    
    for(ll i=0;i<105;i++)
    {
        dp[i]=-1;
    }
    dp[0]=1;
    answer += solve(n,k);
    
    for(ll i=0;i<105;i++)
    {
        dp[i]=-1;
    }
    dp[0]=1;
    if(d>1)
        answer -= solve(n,d-1);
    
    answer+=modder;
    answer%=modder;
    
    cout<<answer<<endl;
    return 0;
}