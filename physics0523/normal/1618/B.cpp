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
    vector<string> s(n-2);
    for(auto &nx : s){cin >> nx;}
    int tg=-1;
    for(int i=0;i<n-3;i++){
      if(s[i][1]!=s[i+1][0]){tg=i;break;}
    }
    string res;
    if(tg==-1){
      res.push_back('a');
    }
    res.push_back(s[0][0]);
    for(int i=0;i<n-2;i++){
      res.push_back(s[i][1]);
      if(i==tg){res.push_back(s[i+1][0]);}
    }
    cout << res << '\n';
  }
  return 0;
}