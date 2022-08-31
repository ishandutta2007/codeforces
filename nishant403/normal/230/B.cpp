#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define F first
#define S second
#define pb push_back
#define f(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define vi vector<int>
#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

vector<bool> isprime(1000001,false);

void sieve()
{
 for(int i=2;i<=1000000;i++)
 {
  if(isprime[i]==false)
      for(int j=i*i;j<=1000000;j+=i)
      isprime[j] = 1;
     
 }
    
}

signed main()
{
Fast;    
    
sieve();
    
  int n,x;
    cin >> n;
    
    while(n--)
    {
     cin >> x;   
     
     
     if(x==1) { cout << "NO\n"; continue; }
     
        if((int)sqrt(x)*(int)sqrt(x) != x ) { cout << "NO\n"; continue; }
        
    if( isprime [ sqrt(x) ] == 0 ) cout << "YES\n";
    else cout << "NO\n";    
        
    }
    
}