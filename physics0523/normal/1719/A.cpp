#include<bits/stdc++.h>

using namespace std;

int f(int x){
  if(x==1){return 0;}
  else if(x%2==0){return 1;}
  else{return 2;}
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int h,w;
    cin >> h >> w;
    if((f(h)+f(w))%2){cout << "Burenka\n";}
    else{cout << "Tonya\n";}
  }
  return 0;
}