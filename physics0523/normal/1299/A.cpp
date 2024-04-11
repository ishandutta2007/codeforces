#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> bk(32,0);
  for(auto &nx : a){
    cin >> nx;
    for(int i=0;i<30;i++){
      if(nx&(1<<i)){bk[i]++;}
    }
  }
  int tg=0;
  for(int i=29;i>=0;i--){
    if(bk[i]==1){tg=(1<<i);break;}
  }
  for(int i=0;i<n;i++){
    if(a[i]&tg){swap(a[0],a[i]);break;}
  }
  for(int i=0;i<n;i++){
    if(i){cout << ' ';}
    cout << a[i];
  }cout << '\n';
  return 0;
}