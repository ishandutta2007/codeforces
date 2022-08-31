#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
#define F first
#define S second
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pll pair<int,int>
#define vl vector<int>


signed main()
{
FAST;    
int n,i,j,k,m;
string s="aeiou";
    
cin >> k;
    
    
    
 for( i=1;i*i<=k;i++)
 {
  if( k%i==0)
  {
   if(i >= 5 && k/i>=5)
   {
    for(n=1;n<=k/i;n++)
    {
    for(j=0;j<i;j++) cout << s[j%5]; 
     rotate(s.begin(),s.begin()+1,s.end());   
    }  
    return 0;   
   }
     
  }
 }
    cout << -1;
}