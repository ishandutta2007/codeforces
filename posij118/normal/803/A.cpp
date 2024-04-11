#include <bits/stdc++.h>
using namespace std;
int main(){ 
    int n, k;
    cin >> n >> k;
    if(k>n*n) cout << "-1";
    
    else{
        
        bool graf[n][n];
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
             graf[i][j]=0;   
            }
        }
        
       
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                 if(i==j && k>0){
                     k--;
                     graf[i][j]=1;
                 }
                 
                 else if(j>i && k>1){
                    k-=2;
                    graf[i][j]=1;
                    graf[j][i]=1;
                 }
                 
                 if(i==j && k==0) break;
                 if(j>i && k<=1) break;
                }
            }
    
        
        if(k==1){
         for(int i=0; i<n; i++){
          if(graf[i][i]==0){
           graf[i][i]=1;
           break;
           
          }
          
          
         }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                
                cout << graf[i][j] << " "; 
                if(j==n-1) cout << endl;
             }
             
             
        }
    
    }

}