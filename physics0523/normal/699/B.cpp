#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  vector<string> s(n);
  for(auto &nx : s){cin >> nx;}
  vector<int> p(n,0),q(m,0);
  int all=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(s[i][j]=='*'){
        p[i]++;q[j]++;all++;
      }
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      int here=p[i]+q[j];
      if(s[i][j]=='*'){here--;}
      if(here==all){
        cout << "YES\n";
        cout << i+1 << ' ' << j+1 << '\n';
        return 0;
      }
    }
  }
  cout << "NO\n";
  return 0;
}