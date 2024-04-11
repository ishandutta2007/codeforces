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
    if(n>m){swap(n,m);}
    if(n==1 || m<=2){cout << "Yes\n";}
    else{cout << "No\n";}
  }
  return 0;
}