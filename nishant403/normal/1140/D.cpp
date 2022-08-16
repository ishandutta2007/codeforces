#include <bits/stdc++.h> 
using namespace std; 
#define ll long long
ll int cost(ll int i,ll int j,ll int k) 
{ 
	return i*j*k; 
} 

ll C(ll n) 
{ 
   if (n < 3) 
      return 0; 
  
   ll table[n+1][n+1]; 
  
   for (ll gap = 1; gap <= n; gap++) 
   { 
      for (ll i = 1, j = gap; j <= n; i++, j++) 
      { 
          if (j < i+2) 
             table[i][j] = 0; 
          else
          { 
              table[i][j] = 99999999999; 
              for (ll k = i+1; k < j; k++) 
              { 
                ll val = table[i][k] + table[k][j] + cost(i,j,k); 
                if (table[i][j] > val) 
                     table[i][j] = val; 
              } 
          } 
      } 
   } 
   return  table[1][n]; 
} 
int main() 
{
    
 ll n;
    cin >> n;
	cout << C(n); 
	return 0; 
}