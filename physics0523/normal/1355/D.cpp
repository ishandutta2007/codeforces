#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,s;
  cin >> n >> s;
  if(n*2<=s){
    cout << "YES\n";
    for(int i=0;i<n;i++){
      if(i){cout << ' ';}
      if(i==n-1){cout << s;}
      else{cout << 2;s-=2;}
    }cout << '\n';
    cout << "1\n";
  }
  else{cout << "NO\n";}
  return 0;
}