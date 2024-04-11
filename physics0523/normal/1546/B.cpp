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
    vector<set<char>> stv(m);
    for(int i=0;i<(2*n-1);i++){
      string s;
      cin >> s;
      for(int j=0;j<m;j++){
        if(stv[j].find(s[j])==stv[j].end()){
          stv[j].insert(s[j]);
        }
        else{
          stv[j].erase(s[j]);
        }
      }
    }
    for(auto &nx : stv){
      cout << (*nx.begin());
    }
    cout << '\n';
  }
  return 0;
}