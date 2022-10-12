#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int l,r,k;
    cin >> l >> r >> k;
    if(l==r){
      if(l==1){cout << "NO\n";}
      else{cout << "YES\n";}
      continue;
    }
    int cnt=1;
    cnt=max(cnt,(r/2)-((l-1)/2));
    cnt=max(cnt,(r/3)-((l-1)/3));
    cnt=max(cnt,(r/5)-((l-1)/5));
    cnt=max(cnt,(r/7)-((l-1)/7));
    if((r-l+1-k)<=cnt){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}