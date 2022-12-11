#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  string s;
  cin >> s;
  int l,r;
  char v1,v2;
  for(int i = 0;i<m;i++){
    cin >> l >> r >> v1 >> v2;
    for(int j = l-1;j<r;j++){
      if(s[j]==v1)s[j] = v2;
    }
  }
  cout << s;
  return 0;
}