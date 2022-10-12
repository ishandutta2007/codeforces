#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int l1,r1,l2,r2,res;
    cin >> l1 >> r1 >> l2 >> r2;
    res=l1+l2;
    if(!(r1<l2 || r2<l1)){res=min(max(l1,l2),res);}
    cout << res << '\n';
  }
  return 0;
}