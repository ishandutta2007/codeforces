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
    int fl=0;
    for(int i=0;i<n;i++){
      int a;
      cin >> a;
      if(a>0){fl|=1;}
      if(a<0){fl|=2;}
    }
    if(fl==2 || fl==3){cout << "No\n";}
    else{
      cout << "Yes\n";
      cout << "300\n";
      for(int i=0;i<300;i++){
        if(i){cout << ' ';}
        cout << i;
      }cout << '\n';
    }
  }
  return 0;
}