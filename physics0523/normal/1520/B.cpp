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
    int val=1,res=0;
    while(val<=n){
      for(int i=1;i<=9;i++){
        if(val*i<=n){res++;}
        else{break;}
      }
      val*=10;val++;
    }
    cout << res << '\n';
  }
  return 0;
}