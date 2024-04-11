#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int a,b;
  for(int i=1;i*i<=n;i++){
    if(n%i==0){
      a=i;
      b=n/i;
    }
  }
  cout << a << ' ' << b << '\n';
  return 0;
}