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
    string s;
    cin >> s;
    n=s.size();
    int cs=abs(((int)s[0])-((int)s[n-1]));
    vector<vector<int>> mem(26);
    for(int i=0;i<n;i++){mem[s[i]-'a'].push_back(i+1);}
    vector<int> res;
    char c=s[0];
    while(1){
      for(auto &nx : mem[c-'a']){res.push_back(nx);}
      if(c==s[n-1]){break;}
      if(c<s[n-1]){c++;}else{c--;}
    }
    cout << cs << " " << res.size() << "\n";
    for(int i=0;i<res.size();i++){
      if(i){cout << " ";}
      cout << res[i];
    }cout << "\n";
  }
  return 0;
}