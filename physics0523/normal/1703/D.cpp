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
    vector<string> s(n);
    set<string> st;
    for(int i=0;i<n;i++){
      cin >> s[i];
      st.insert(s[i]);
    }
    for(int i=0;i<n;i++){
      bool ok=false;
      for(int j=1;j<s[i].size();j++){
        string pre,suf;
        for(int k=0;k<s[i].size();k++){
          if(k<j){pre.push_back(s[i][k]);}
          else{suf.push_back(s[i][k]);}
        }
        if(st.find(pre)!=st.end() && st.find(suf)!=st.end()){ok=true;break;}
      }
      if(ok){cout << "1";}
      else{cout << "0";}
    }cout << "\n";
  }
  return 0;
}