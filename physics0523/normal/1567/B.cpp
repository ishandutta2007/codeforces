#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> rx(500000);
  rx[0]=0;
  for(int i=1;i<500000;i++){rx[i]=(rx[i-1]^i);}

  int t;
  cin >> t;
  while(t>0){
    t--;
    int a,b;
    cin >> a >> b;
    if(rx[a-1]==b){cout << a << '\n';}
    else if((rx[a-1]^b)==a){cout << a+2 << '\n';}
    else{cout << a+1 << '\n';}
  }
  return 0;
}