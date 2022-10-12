#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,m,k;
    cin >> n >> m >> k;
    if(n*m-1==k){cout << "YES\n";}else{cout << "NO\n";}
  }
  return 0;
}