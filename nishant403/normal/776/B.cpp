#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define N 100001

vector<bool> isprime(N+1,1);

void sieve()
{
 isprime[0]=isprime[1]=1;
    for(int i=2;i<=N;i++)
       if(isprime[i])
        for(int j=i*i;j<=N;j+=i) isprime[j]=false;   
}

signed main()
{
    fast;
    int n,i,j;
    sieve();
    
    cin >> n;
    
    for(i=2;i<=n+1;i++)
    {
     if(isprime[i]==false)
     {
      cout << 2 << "\n";  
         for(j=2;j<=n+1;j++) cout << isprime[j]+1 << " ";
      return 0;
     }
        
    }
    
    cout << 1 << "\n";
    for(j=2;j<=n+1;j++) cout << isprime[j] << " ";
    
    
}