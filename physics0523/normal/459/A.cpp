#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int x1,y1,x2,y2;
  cin >> x1 >> y1 >> x2 >> y2;
  if(x1==x2){
    int d=abs(y1-y2);
    cout << x1+d << ' ' << y1 << ' ';
    cout << x1+d << ' ' << y2 << '\n';
    return 0;
  }
  if(y1==y2){
    int d=abs(x1-x2);
    cout << x1 << ' ' << y1+d << ' ';
    cout << x2 << ' ' << y1+d << '\n';
    return 0;
  }
  if(abs(x1-x2)==abs(y1-y2)){
    cout << x1 << ' ' << y2 << ' ';
    cout << x2 << ' ' << y1 << '\n';
    return 0;
  }
  cout << "-1\n";
  return 0;
}