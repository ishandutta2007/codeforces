#include<bits/stdc++.h>

using namespace std;

// vector<int> f(string s){
//   vector<int> res;
//   int p=0,q=0;
//   for(auto &nx : s){
//     if(nx=='0'){p++;}
//     else{q=max(p,q)+1;}
//     res.push_back(max(p,q));
//   }
//   return res;
// }
//
// int main(){
//   for(int n=1;n<=12;n++){
//     map<vector<int>,vector<string>> mp;
//     for(int i=0;i<(1<<n);i++){
//       string s;
//       for(int j=0;j<n;j++){
//         if(i&(1<<j)){s.push_back('1');}
//         else{s.push_back('0');}
//       }
//       reverse(s.begin(),s.end());
//       mp[f(s)].push_back(s);
//     }
//     cout << "n = " << n << ":\n";
//     for(auto &nx : mp){
//       for(auto &ny : nx.second){
//         cout << ny << "\n";
//       }cout << "\n";
//     }cout << "\n";
//   }
//   return 0;
// }

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  reverse(s.begin(),s.end());

  string t;
  int sz=0;
  for(auto &nx : s){
    if(nx=='0'){
      t.push_back('0');
      sz++;
    }
    else{
      if(sz>0){
        t.push_back('1');
        sz--;
      }
      else{t.push_back('0');}
    }
  }

  reverse(t.begin(),t.end());
  cout << t << "\n";
  return 0;
}