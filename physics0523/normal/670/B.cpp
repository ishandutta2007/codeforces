#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  long long k;
  cin >> n >> k;
  vector<int> id(n+1);
  for(int i=1;i<=n;i++){cin >> id[i];}
  for(int i=1;i<=n;i++){
    if(k<=i){cout << id[k] << '\n';break;}
    else{k-=i;}
  }
  return 0;
}