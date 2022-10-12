#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    string r,b;
    cin >> r >> b;
    int rc=0,bc=0;
    for(int i=0;i<n;i++){
      if(r[i]>b[i]){rc++;}
      else if(r[i]<b[i]){bc++;}
    }
    if(rc>bc){cout << "RED\n";}
    else if(rc<bc){cout << "BLUE\n";}
    else{cout << "EQUAL\n";}
  }
  return 0;
}