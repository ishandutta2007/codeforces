// Example program
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  if(n%2==0){
      cout << n/2 << endl;
     for(int i=0; i<n/2; i++){
         cout << "2 ";
     }
  }
  
  else {
      cout << n/2 << endl;
      cout << "3 ";
     for(int i=1; i<n/2; i++){
         cout << "2 ";
     }
  }
  
  
}