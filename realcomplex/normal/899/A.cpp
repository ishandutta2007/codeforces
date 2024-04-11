#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  int k;
  int v1 = 0,v2 = 0;
  for(int i = 0;i<n;i++){
    cin >> k;
    if(k==1)v1++;
    else v2++;
  }
  cout << max(min(v1,v2)+((v1-min(v1,v2))/3),v1/3);
  return 0;
}