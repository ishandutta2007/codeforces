#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> bk(26,0);
    for(int i=0;i<(2*n+1);i++){
      string s;
      cin >> s;
      for(auto &nx : s){
        bk[nx-'a']++;
      }
    }
    for(int i=0;i<26;i++){
      if(bk[i]&1){
        cout << (char)('a'+i) << '\n';
      }
    }
  }
  return 0;
}