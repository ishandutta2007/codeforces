#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int a,b,c;
    cin >> a >> b >> c;
    int f=abs(a-1);
    int s=abs(c-b)+abs(c-1);
    int r=3;
    if(f<s){r=1;}
    if(f>s){r=2;}
    cout << r << "\n";
  }
  return 0;
}