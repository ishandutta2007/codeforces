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
    int a=0,b=0,c=0;
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      if(v==1){a++;}
      if(v==2){b++;}
      if(v==3){c++;}
    }
    cout << a+c << '\n';
  }
  return 0;
}