#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int cur=0;
  for(int i=1;;i++){
    cur+=i;
    if(n<cur){
      cout << i-1 << '\n';
      return 0;
    }
    n-=cur;
  }
  return 0;
}