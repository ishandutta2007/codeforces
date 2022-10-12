#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    if(n==1 && m==1){cout << "0\n";continue;}
    cout << ((n-1)+(m-1))+min(n-1,m-1)+1 << "\n";
  }
  return 0;
}