#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m, k, mini;

  cin >> n >> m >> k; 
    mini=n;
  
  int ceny[n];
  
  for(int i=0; i<n; i++){
   cin >> ceny[i];   
  }
  
  for(int i=m-2; i>-1; i--){
   if(ceny[i]<=k && ceny[i]!=0){
    mini=m-1-i;
    break;
   }
  }
  
  for(int i=m; i<n; i++){
   if(ceny[i]<=k && ceny[i]!=0){
    if(i-m+1<mini) mini=i-m+1;
    break;
   }
  }
  
  cout << 10*mini;
}