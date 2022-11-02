#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k, m;
    cin >> n >> k;
    
    m=n%10;
    
    for(int i=1; i<10; i++){
     if((m*i)%10==0 || (m*i)%10==k){
      cout << i;
      break;
     }
    }
  
}