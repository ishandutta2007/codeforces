#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,w1,w2,w,b;
    cin >> n >> w1 >> w2 >> w >> b;
    int b1=n-w1,b2=n-w2;
    w1+=w2;w1/=2;
    b1+=b2;b1/=2;
    if(w1>=w && b1>=b){cout << "Yes\n";}else{cout << "No\n";}
  }
  return 0;
}