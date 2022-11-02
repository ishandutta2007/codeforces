#include <bits/stdc++.h>
using namespace std;
int main(){ 
    int n;
    cin >> n;
    int a[n];
    int d[n];
    for (int i=0; i<n; i++){
     cin >> a[i];   
    }
    
    int nula=-n;
    
    for(int i=0; i<n; i++){
     if(a[i]==0){
         for(int j=nula+1; j<i+1; j++){
          if(j>=0){
           d[j]=min(j-nula, i-j);   
          }
         }
     
     nula=i;
     
     }
    }
    
    nula=2*n;
    
    for(int i=n-1; i>-1; i--){
     if(a[i]==0){
         for(int j=nula-1; j>i-1; j--){
          if(j<=n-1){
           d[j]=min(nula-j, j-i);   
          }
         }
     
     nula=i;
     
     }
    }
    
    
    for(int i=0; i<n; i++){
     cout << d[i] << " ";   
    }
    
}