#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  int res=min(n,m);
  res=min(res,(n+m)/3);
  cout << res << '\n';
  return 0;
}