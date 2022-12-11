#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  char f;
  int low = 0;
  int bal = 0;
  for(int i = 0 ; i < n ; i ++ ){
    cin >> f;
    if(f == '(')
      bal ++ ;
    else
      bal --;
    low = min(low, bal);
  }
  if(bal == 0 && low >= -1){
    cout << "Yes\n";
  }
  else{
    cout << "No\n";
  }
  return 0;
}