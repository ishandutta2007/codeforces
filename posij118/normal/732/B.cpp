#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k, suma;
  suma=0;
  cin >> n >> k;
  
  int walk[n];
  for(int i=0; i<n; i++){
   cin >> walk[i];   
  }
  
  for(int i=1; i<n; i++){
   if(walk[i]+walk[i-1]<k){
       suma+=k-walk[i]-walk[i-1];
       walk[i]=k-walk[i-1];   
  }
  }
  cout << suma << endl;
  
  for(int i=0; i<n; i++){
   cout << walk[i] << " ";   
  }
  
}