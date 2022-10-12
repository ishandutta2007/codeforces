#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int o,i;
  cin >> o >> i;
  if((i+1)<o){
    cout << "-1\n";
    return 0;
  }
  else if((i+1)==o){
    cout << '0';
    for(int k=0;k<i;k++){cout << "10";}
    cout << '\n';
    return 0;
  }
  else if(i==o){
    for(int k=0;k<i;k++){cout << "10";}
    cout << '\n';
    return 0;
  }
  else if(i<=2*(o+1)){
    int rem=i-(o+1);
    for(int k=0;k<(o+1);k++){
      cout << "1";
      if(rem>0){
        cout << "1";
        rem--;
      }
      if(k==o){break;}
      cout << "0";
    }
    return 0;
  }
  else{
    cout << "-1\n";
    return 0;
  }
  return 0;
}