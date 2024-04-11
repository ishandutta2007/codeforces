#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n, m, sumall, suma;
    sumall=0;
    
    cin >> n >> m;
    int mood[n];
    int subarray[m][2];
    
    for(int i=0; i<n; i++) {
       cin >> mood[i]; 
    }
    
    for(int i=0; i<m; i++) {
     cin >> subarray[i][0] >> subarray[i][1];   
    }
    
    for(int i=0; i<m; i++) {
        suma=0;
        for(int j=subarray[i][0]; j<subarray[i][1]+1; j++){
          suma+=mood[j-1];    
        }
        if(suma>0) sumall+=suma;
        
    }
    
    cout << sumall;
}