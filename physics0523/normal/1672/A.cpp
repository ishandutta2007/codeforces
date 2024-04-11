#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    int cut=0;
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      cut+=(v-1);
    }
    if(cut%2){cout << "errorgorn\n";}
    else{cout << "maomao90\n";}
  }
  return 0;
}