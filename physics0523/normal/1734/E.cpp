#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> b(n);
  for(auto &nx : b){
    cin >> nx;
  }

  for(int i=0;i<n;i++){
    int trans=(i*i)%n;
    trans=(n+b[i]-trans)%n;
    for(int j=0;j<n;j++){
      if(j){cout << " ";}
      cout << (i*j+trans)%n;
    }cout << "\n";
  }
  return 0;
}