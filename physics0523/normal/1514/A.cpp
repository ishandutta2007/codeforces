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
    bool fl=false;
    for(int q=0;q<n;q++){
      int v;
      cin >> v;
      for(int i=0;i<=100;i++){
        if(i*i==v){break;}
        if(i==100){fl=true;}
      }
    }
    if(fl){cout << "YES\n";}else{cout << "NO\n";}
  }
  return 0;
}