#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int jidla[3];
  cin >> jidla[0] >> jidla[1] >> jidla[2];
  
  sort(jidla, jidla + 3);
  
  if(jidla[1]==jidla[2]){
   if(jidla[0]==jidla[1]) cout << "0";
   else cout << jidla[1]-jidla[0]-1;
  }
  
  else cout << 2*jidla[2]-jidla[0]-jidla[1]-2; 
      
}