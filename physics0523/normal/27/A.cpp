#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> bk(5005,0);
  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    bk[x]=1;
  }
  for(int i=1;;i++){
    if(bk[i]==0){cout << i << "\n";return 0;}
  }
  return 0;
}