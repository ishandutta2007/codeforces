#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k=1;
    cin >> n;
    vector<int> res;
    while(n>0){
      if(n%10!=0){res.push_back((n%10)*k);}
      n/=10;k*=10;
    }
    cout << res.size() << '\n';
    for(int i=0;i<res.size();i++){
      if(i){cout << ' ';}
      cout << res[i];
    }cout << '\n';
  }
  return 0;
}