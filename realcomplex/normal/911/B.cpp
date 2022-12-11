#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,a,b;
  cin >> n >> a >> b;
  int l,r;
  for(int x = 500;x>=1;x--){
    l=a/x;
    r=b/x;
    if(l==0||r==0)continue;
    if(l+r>=n){
      cout << x << "\n";
      return 0;
    }
  }
  return 0;
}