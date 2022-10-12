#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;
  cin >> n >> k;
  vector<int> a(n),b(k);
  for(auto &nx : a){cin >> nx;}
  for(auto &nx : b){cin >> nx;}
  sort(b.begin(),b.end());
  if(b[0]!=b[k-1]){cout << "Yes\n";return 0;}
  int fill=b[0];
  for(auto &nx : a){
    if(nx==0){nx=fill;}
  }
  for(int i=1;i<n;i++){
    if(a[i-1]>=a[i]){cout << "Yes\n";return 0;}
  }
  cout << "No\n";
  return 0;
}