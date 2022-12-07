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
#define vi vector<int>
#define pair pair<int,int>
#define F first
#define S second
#define mem(x) memset(x,0,sizeof(x))
#define PI 3.1415926535897932384626433832795l
#define deci(n) cout<<fixed<<setprecision(n);


#define MOD 1000000007
using namespace std;


int dp[1004];
ll ncr[1004][1004];

int ones(int n)
{
  int cnt = 0;
  while(n)
  {
    if(n%2 == 1)
    {
      cnt++;
    }
    n /= 2;
  }
  return cnt;
}

int main()
{
  string n;
  int k;
  cin >> n >> k;
  for(int i = 0; i <= 1000; i++)
  {
    ncr[i][0] = 1;
  }
  for(int i = 1; i <= 1000; i++)
  {
    for(int j = 1; j <= 1000; j++)
    {
      ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j])%MOD;
    }
  }

  dp[1] = 0;
  for(int i = 2; i <= 1000; i++)
  {
    dp[i] = dp[ones(i)] + 1;
    //cout<<i<<" :"<<dp[i]<<endl;
  }

  if(k == 0)
  {
    cout << "1\n";
    return 0;
  }

  long long nones = 0, ans = 0;
  for(int i = 0; i < n.size(); i++)
  {
    if(n[i] == '0')
    {
      continue;
    }
    for(int j = max(nones, 1LL); j < 1000; j++)
    {
      if(dp[j] == k-1)
      {
        ans = (ans + ncr[n.size()-i-1][j-nones])%MOD;
        if(i == 0 && k == 1)
        {
          ans = (ans+MOD-1)%MOD;
        }
      }
    }
    nones++;
  }

  int cnt = 0;
  for(int i = 0; i < n.size(); i++)
  {
    if(n[i] == '1')
    {
      cnt++;
    }
  }
  if(dp[cnt] == k-1)
  {
    ans = (ans + 1)%MOD;
  }
  cout << ans << endl;

  return 0;
}