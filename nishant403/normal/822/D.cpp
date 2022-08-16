#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int N =(5*1e6)+5;
vector<int> isprime(N+1,0);

int M =1e9+7;

void sieve()
{
    for(int i=2;i<N;i++)
    {
        if(isprime[i]==0)
        {
            for(int j=i*i;j<N;j+=i)
              if(isprime[j]==0) isprime[j]=i; 
        }
    }
}


vector<int> dp(N+1,0);

void calc()
{
    
  for(int i=2;i<=(5*1000000);i++)
  {
  if(isprime[i]==0) {dp[i]=((i*(i-1))/2)%M; continue; }
       
 int groups = i/isprime[i];   
 int members = isprime[i];
 
 int comp=(groups*dp[members])%M;     
    
 dp[i] = ( comp +dp[groups] ) %M;
 }
    
}

signed main()
{
    fast;
    
    sieve();
    calc();
    
    int t,l,r;
    cin >> t >> l >> r;
 
    int ans = 0;
    int s=t,kk=0;
    t=1;
    
    for(int i=l;i<=r;i++)
    {
     kk=(dp[i]*t)%M;
     ans=(ans+kk)%M;   
     t=(t*s)%M;   
    }
    
    cout << ans;
}