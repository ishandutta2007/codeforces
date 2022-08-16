#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define f(i,n) for(i=0;i<n;i++)
#define F first
#define S second
#define pb push_back
#define pll pair<long long,long long>
#define vl vector<long> 

int main()
{
 fast;   
 ll n,k,i,j,ans=0;
 string s;
    
 cin >> n;
  int sr[n];
  int cs[n];    
  
    f(i,n) cs[i]=1;
    
  f(i,n)
  {
   cin >> k >> j;
      
  sr[i]=j;    
  if(j==0) cs[k-1]=0;
  }
    
    priority_queue<ll,vector<ll>,greater<ll> > ss;
    
   f(i,n) if(cs[i] && sr[i]) ss.push(i+1);
  
       if(ss.empty())
   { cout << -1;
   }
    else
   while(!ss.empty() )
   {
      cout << ss.top() <<  " " ; ss.pop();
       
   }
   
       
}