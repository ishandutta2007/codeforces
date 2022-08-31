#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define f(i,n) for(int i=0;i<n;i++)
#define F first
#define S second

const int N = 2750133;
vector<int> isprime(N,0);
vector<int> arr(N,0);
vector<int> primes;

void sieve()
{
 for(int i=2;i*i<N;i++)
 {
  if(isprime[i]==0)
      for(int j=i*i;j<N;j+=i)
         if(isprime[j]==0) isprime[j] = i;
 }
    
 for(int i=2;i<N;i++) if(isprime[i]==0) primes.pb(i);   
}

signed main()
{
 ios_base::sync_with_stdio(0);   
 cin.tie(0);
 cout.tie(0);
    
 sieve();   
    
 int n,x;
 cin >> n;   
     
 f(i,n+n) 
 {   
     cin >> x;
     arr[x]++; 
 }
    
    //for nonprime
 for(int i=N;i>=2;i--)  
 {     
   while(isprime[i]>0 && arr[i])
   {
    cout << i << " ";   
    assert(arr[i/isprime[i]] > 0);   
    arr[i/isprime[i]]--;   
    arr[i]--;
   } 
 }
    
  //for prime
 for(int i=2;i<=N;i++)
 {
    while(isprime[i]==0 && arr[i])
    {
     cout << i << " ";
     assert(arr[primes[i-1]] > 0);  
     arr[primes[i-1]]--;
     arr[i]--;
    }
 }
    
}