#include<bits/stdc++.h>

using namespace std;

int f(int x,int a){
  return (x/a)+(x%a);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int l,r,a,res;
    cin >> l >> r >> a;
    res=f(r,a);
    int cur=(r/a)*a;
    if(l<=(cur-1)){res=max(res,f(cur-1,a));}
    cout << res << '\n';
  }
  return 0;
}