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
 ll n,k,i,j,a=0;
 string s;
    
 cin >> n;
    
 cin >> s;
    
  f(i,n)
  {
      if( (s[i]-'0') % 2 == 0 )
          a+=(i+1);
  }
   cout << a; 
}