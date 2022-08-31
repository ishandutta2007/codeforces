#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define f(i,n) for(int i=0;i<n;i++)
#define F first
#define S second

const int N = 100;
const int T = 1e5+10;
const double eps = 1e-9;
 
vector<int> isprime(N,-1),mob(N),ff(T),ans(T);
pair<int,int> a[T];
int lim[61]={0,0,0,1000000,31623,3982,1000,373,178,100,67,46,33,25,20,16,13,11,10,9,8,7,6,6,5,5,5,4,4,4,4,3,3,3,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};

void sieve()
{
  isprime[0] = isprime[1] =  0;
    
  for(int i=2;i<N;i++)
  {
      if(isprime[i] == -1)
      {
    for(int j=i*i;j<N;j+=i)
        isprime[j] = i;
      }
  }
    
  mob[0] = 0;
  mob[1] = 1;
    
  for(int i=2;i<N;i++)
  {
    if(isprime[i] == -1) mob[i] = -1;
    else if((i/isprime[i]) % isprime[i] == 0) mob[i] = 0;
    else mob[i] = mob[i/isprime[i]]*mob[isprime[i]];
  }      
}

int pw(int a,int b)
{
   int res = 1;
    
   while(b)
   {
    if(b&1) res=res*a;
    a=a*a;
    b>>=1;    
   }
    
   return res;
}

int go(int n)
{
 return sqrt(n);   
}

void solve(int n)
{
    
f(i,n)
{
   ans[i] = a[i].F - go(a[i].F);
    
   for(int j=3;j<=59;j++)
   {
    while(pw(lim[j],j) > a[i].F) lim[j]--;
    ans[i]+=((lim[j]-1)*mob[j]);
   }
}
    
f(i,n) ff[a[i].S] = ans[i]; 
f(i,n) cout << ff[i]<<"\n";        
}

signed main()
{
 ios::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
    
 sieve();   
       
 int t;
 cin >> t;
 f(i,t) cin >> a[i].F;
 f(i,t) a[i].S = i;  
 sort(a,a+t);
 reverse(a,a+t);   
 solve(t);
}